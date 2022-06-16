/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 03:05:11 by mcauchy           #+#    #+#             */
/*   Updated: 2022/05/29 23:09:41 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_parsed_map(char **map, t_window *win)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] && i < win->size_x)
		{
			if ()
		}
	}
}

void	put_string(t_window *win)
{
	int	size_y;

	size_y = win->size_y;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->sprite->wall, 0, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, (size_y + 1) * 32, 0xFF00FF, ft_itoa(win->movement));
	printf("mvmts : %d\n", win->movement);
	return ;
}

t_coord	*parse_map_with_xpm(char **map, t_sprite *sprite, t_window *win)
{
	int		i;
	int		j;
	t_coord	*player;

	i = 0;
	j = 0;
	player = (t_coord *)malloc(sizeof(t_coord));
	win->polo = 0;
	if (!player)
		return (NULL);
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
				player->x = j;
				player->y = i;
				player->img = sprite->masta_playa;
				mlx_put_image_to_window(win->mlx_ptr,
					win->win_ptr, sprite->masta_playa, j * 32, i * 32);
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
	return (player);
}
