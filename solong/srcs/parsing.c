/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 03:05:11 by mcauchy           #+#    #+#             */
/*   Updated: 2022/05/30 17:03:45 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_sprite(t_window *win, char c)
{
	if (c == 'P')
		win->check->masta_playa++;
	else if (c == 'C')
		win->check->kagugra++;
	else if (c == 'E')
		win->check->exit++;
	if ((win->check->exit != 1 || win->check->kagugra == 0 ||
			win->check->masta_playa != 1) && win->check->end_of_map == 1)
	{
		printf("exit %d, kagugra %d, masta_playa %d\n",
				win->check->exit, win->check->kagugra, win->check->masta_playa);
		exit(0);
	}
	return ;
}

void	check_parsed_map(char **map, t_window *win)
{
	int	i;
	int	j;

	j = 0;
	while (j < win->size_y)
	{
		i = 0;
		while (i < win->size_x - 1)
		{
			if ((j == 0 || j == win->size_y) && map[j][i] != '\n')
			{
				if (map[j][i] != '1')
				{
					printf("Error: map must be surrounded by walls %d\n", j);
					exit(0);
				}
			}
			else
			{
				if ((map[j][0] != '1' || map[j][win->size_x - 2] != '1'))
				{
					printf("Error: map must be surrounded by walls %d\n", j);
					exit(0);
				}
			}
			if (j == win->size_y - 1 && i == win->size_x - 2)
				win->check->end_of_map = 1;
			check_sprite(win, map[j][i]);
			i++;
		}
		j++;
	}
}

void	put_string(t_window *win)
{
	int		size_y;
	char	*num;

	size_y = win->size_y;
	num = ft_itoa(win->movement);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->sprite->wall, 0, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->img->size_x / 2, win->size_x / 2, 0xFFFF00, num);
	free(num);
	return ;
}

void	parse_map_with_xpm(char **map, t_sprite *sprite, t_window *win)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	win->polo = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(win->mlx_ptr,
					win->win_ptr, sprite->wall, j * 32, i * 32);
			else if (map[i][j] == 'P')
			{
				win->player->x = j;
				win->player->y = i;
				mlx_put_image_to_window(win->mlx_ptr,
					win->win_ptr, win->sprite->masta_playa, j * 32, i * 32);
			}
			else if (map[i][j] == 'E')
			{
				if (win->polo == -1)
				{
					mlx_destroy_window(win->mlx_ptr, win->win_ptr);
					exit(0);
				}
				mlx_put_image_to_window(win->mlx_ptr,
					win->win_ptr, sprite->exit, j * 32, i * 32);
			}
			else if (map[i][j] == '0')
				mlx_put_image_to_window(win->mlx_ptr,
					win->win_ptr, sprite->background, j * 32, i * 32);
			else if (map[i][j] == 'C')
			{
				win->polo++;
				mlx_put_image_to_window(win->mlx_ptr,
					win->win_ptr, sprite->kagugra, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
	put_string(win);
	return ;
}
