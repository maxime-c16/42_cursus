/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:52:52 by mcauchy           #+#    #+#             */
/*   Updated: 2022/05/29 22:56:28 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
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
	int	size;
	int	fd;

	size = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd) != 0)
		size++;
	if (fd > 0)
		close(fd);
	return (size);
}

void	ft_free_sprite(t_sprite *sprite)
{
	free(sprite->background);
	free(sprite->exit);
	free(sprite->kagugra);
	free(sprite->wall);
	free(sprite->masta_playa);
	free(sprite);
}

void	free_struct(t_window *win)
{
	free(win->mlx_ptr);
	free(win->img_ptr);
	ft_free_sprite(win->sprite);
	ft_free_tab(win->map);
	free(win->player);
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

t_window	*init_window(t_window *win, char **map)
{
	win->size_x = ft_strlen(map[0]);
	printf("test taille %d\n", win->size_y);
	win->win_ptr = mlx_new_window(win->mlx_ptr, (win->size_x - 1) * 32,
			win->size_y * 32, win->title);
	win->x_min = 0;
	win->y_min = 0;
	win->img = malloc(sizeof(t_img));
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
	else
		return (0);

}

int	check_wall_exit_polo(char **tab, int x, int y, t_window *win)
{
	if (tab[y][x] == 'C')
	{
		win->polo--;
		printf("polo remaining : %d\n", win->polo);
	}
	else if (tab[y][x] == '1')
		return (1);
	else if (tab[y][x] == 'E' && win->polo > 0)
		return (2);
	else if (tab[y][x] == 'E' && win->polo == 0)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		printf("you win\n");
		exit(0);
	}
	return (0);
}

int	key_hook(int keycode, t_window *win)
{
	//printf("keycode: %d\n", keycode);
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
		win->player = parse_map_with_xpm(win->map, win->sprite, win);
	}
	else if (keycode == LEFT_ARROW && !check_wall_exit_polo(win->map,
			win->player->x - 1, win->player->y, win))
	{
		win->player->x -= 1;
		win->map[win->player->y][win->player->x + 1] = '0';
		win->map[win->player->y][win->player->x] = 'P';
		win->player = parse_map_with_xpm(win->map, win->sprite, win);
	}
	else if (keycode == UP_ARROW && !check_wall_exit_polo(win->map,
			win->player->x, win->player->y - 1, win))
	{
		win->player->y -= 1;
		win->map[win->player->y + 1][win->player->x] = '0';
		win->map[win->player->y][win->player->x] = 'P';
		win->player = parse_map_with_xpm(win->map, win->sprite, win);
	}
	else if (keycode == DOWN_ARROW && !check_wall_exit_polo(win->map,
			win->player->x, win->player->y + 1, win))
	{
		win->player->y += 1;
		win->map[win->player->y - 1][win->player->x] = '0';
		win->map[win->player->y][win->player->x] = 'P';
		win->player = parse_map_with_xpm(win->map, win->sprite, win);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_window	*view;
	char		**map;
	int			fd;

	if (ac != 2)
		return (0);
	map = NULL;
	fd = open(av[1], O_RDONLY);
	view = malloc(sizeof(t_window));
	view->mlx_ptr = mlx_init();
	view->title = "so_long";
	view->fd = fd;
	view->size_y = get_size_y(av[1]);
	map = init_map(fd, view);
	printf("test taille map %d\n", ft_strlen(map[0]));
	view = init_window(view, map);
	view->sprite = init_sprite(view);
	view->player = parse_map_with_xpm(view->map, view->sprite, view);
	mlx_key_hook(view->win_ptr, key_hook, view);
	mlx_loop(view->mlx_ptr);
	return (0);
}
