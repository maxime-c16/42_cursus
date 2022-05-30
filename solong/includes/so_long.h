/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:43:48 by mcauchy           #+#    #+#             */
/*   Updated: 2022/05/30 17:06:06 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifdef __APPLE__

#  define OS_X "Macos"
#  define LEFT_ARROW 123
#  define RIGHT_ARROW 124
#  define DOWN_ARROW 125
#  define UP_ARROW 126
#  define ESCAPE 53

# else

#   define OS_X "Linux"
# 	define LEFT_ARROW 65361
# 	define RIGHT_ARROW 65363
# 	define UP_ARROW 65362
# 	define DOWN_ARROW 65364
# 	define ESCAPE 65307

# endif

typedef struct	s_img
{
	int		size_x;
	int		size_y;
}				t_img ;

typedef	struct	s_sprite
{
	void	*wall;
	void	*masta_playa;
	void	*exit;
	void	*background;
	void	*kagugra;
}				t_sprite;

typedef	struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef	struct s_check
{
	int masta_playa;
	int exit;
	int kagugra;
	int	end_of_map;
}				t_check;

typedef struct  s_window
{
	void		*mlx_ptr;
	void		*img_ptr;
	t_img		*img;
	t_coord		*player;
	t_sprite	*sprite;
	void		*win_ptr;
	int			size_x;
	int			size_y;
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	int			movement;
	char		*title;
	char		**map;
	int			polo;
	int			size_line;
	int			fd;
	t_check		*check;
}				t_window ;

char	*get_next_line(int fd);
void	parse_map_with_xpm(char **map, t_sprite *sprite, t_window *win);
void	ft_print_tab(char **tab);

//utils functions

char	*ft_itoa(int n);
int		get_size_y(char *map);
void	check_parsed_map(char **map, t_window *win);

#endif
