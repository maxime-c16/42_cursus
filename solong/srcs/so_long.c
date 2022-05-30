/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:52:52 by mcauchy           #+#    #+#             */
/*   Updated: 2022/05/30 17:53:55 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	get_size_y(char *map)
{
	int		size;
	int		fd;
	char	*str;

	size = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str != 0)
	{
		free(str);
		str = get_next_line(fd);
		size++;
	}
	if (fd > 0)
		close(fd);
	free(str);
	return (size);
}

static	void	ft_free_sprite(t_window *win)
{
	mlx_destroy_image(win->mlx_ptr, win->sprite->background);
	mlx_destroy_image(win->mlx_ptr, win->sprite->masta_playa);
	mlx_destroy_image(win->mlx_ptr, win->sprite->kagugra);
	mlx_destroy_image(win->mlx_ptr, win->sprite->exit);
	free(win->sprite);
}

void	free_struct(t_window *win)
{
	free(win->img_ptr);
	ft_free_sprite(win);
	ft_free_tab(win->map);
	free(win->player);
	free(win->mlx_ptr);
	free(win);
}

t_sprite	*init_sprite(t_window *win)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->wall = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/wall.xpm", &win->img->size_x, &win->img->size_y);
	sprite->masta_playa = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/masta_playa.xpm", &win->img->size_x, &win->img->size_y);
	sprite->exit = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/exit.xpm", &win->img->size_x, &win->img->size_y);
	sprite->background = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/background.xpm", &win->img->size_x, &win->img->size_y);
	sprite->kagugra = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/kagugra.xpm", &win->img->size_x, &win->img->size_y);
	return (sprite);
}

t_check	*init_check(void)
{
	t_check	*check;

	check = (t_check *)malloc(sizeof(t_check));
	if (!check)
		return (NULL);
	check->exit = 0;
	check->kagugra = 0;
	check->masta_playa = 0;
	check->end_of_map = 0;
	return (check);
}

t_window	*init_window(t_window *win, char **map)
{
	win->size_x = ft_strlen(map[0]);
	win->player = (t_coord *)malloc(sizeof(t_coord));
	win->win_ptr = mlx_new_window(win->mlx_ptr, (win->size_x - 1) * 32,
			win->size_y * 32, win->title);
	win->x_min = 0;
	win->y_min = 0;
	win->player->x = 0;
	win->player->y = 0;
	win->img = malloc(sizeof(t_img));
	win->check = init_check();
	win->img->size_x = 32;
	win->img->size_y = 32;
	win->polo = 0;
	win->map = map;
	win->size_line = ft_strlen(map[0]);
	win->img_ptr = NULL;
	win->movement = 0;
	return (win);
}

char	**init_map(int fd, t_window *win)
{
	int		i;
	char	**tab;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (win->size_y + 1));
	tab[i] = get_next_line(fd);
	while (tab[i] != NULL)
	{
		i++;
		tab[i] = get_next_line(fd);
	}
	tab[i++] = NULL;
	if (fd > 0)
		close(fd);
	return (tab);
}

int	check_keycode(int keycode, t_window *win)
{
	if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW ||
			keycode == UP_ARROW || keycode == DOWN_ARROW)
	{
		win->movement++;
		return (1);
	}
	return (0);

}

int	check_wall_exit_polo(char **tab, int x, int y, t_window *win)
{
	if (tab[y][x] == 'C')
		win->polo--;
	else if (tab[y][x] == '1')
		return (1);
	else if (tab[y][x] == 'E' && win->polo > 0)
		return (2);
	else if (tab[y][x] == 'E' && win->polo == 0)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		free_struct(win);
		exit(0);
	}
	return (0);
}

int	key_hook(int keycode, t_window *win)
{
	check_keycode(keycode, win);
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		free_struct(win);
		exit(0);
	}
	else if (keycode == RIGHT_ARROW && !check_wall_exit_polo(win->map,
			win->player->x + 1, win->player->y, win))
	{
		win->player->x += 1;
		win->map[win->player->y][win->player->x - 1] = '0';
		win->map[win->player->y][win->player->x] = 'P';
		parse_map_with_xpm(win->map, win->sprite, win);
	}
	else if (keycode == LEFT_ARROW && !check_wall_exit_polo(win->map,
			win->player->x - 1, win->player->y, win))
	{
		win->player->x -= 1;
		win->map[win->player->y][win->player->x + 1] = '0';
		win->map[win->player->y][win->player->x] = 'P';
		parse_map_with_xpm(win->map, win->sprite, win);
	}
	else if (keycode == UP_ARROW && !check_wall_exit_polo(win->map,
			win->player->x, win->player->y - 1, win))
	{
		win->player->y -= 1;
		win->map[win->player->y + 1][win->player->x] = '0';
		win->map[win->player->y][win->player->x] = 'P';
		parse_map_with_xpm(win->map, win->sprite, win);
	}
	else if (keycode == DOWN_ARROW && !check_wall_exit_polo(win->map,
			win->player->x, win->player->y + 1, win))
	{
		win->player->y += 1;
		win->map[win->player->y - 1][win->player->x] = '0';
		win->map[win->player->y][win->player->x] = 'P';
		parse_map_with_xpm(win->map, win->sprite, win);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_window	*win;
	char		**map;

	if (ac != 2)
		return (0);
	printf("Setting up macros and variables for OS: %s\n", OS_X);
	map = NULL;
	win = malloc(sizeof(t_window));
	win->mlx_ptr = mlx_init();
	win->title = "so_long";
	win->fd = open(av[1], O_RDONLY);
	win->size_y = get_size_y(av[1]);
	map = init_map(win->fd, win);
	win = init_window(win, map);
	check_parsed_map(map, win);
	win->sprite = init_sprite(win);
	parse_map_with_xpm(win->map, win->sprite, win);
	mlx_key_hook(win->win_ptr, key_hook, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
