#include "mlbx/mlx.h"
#include <math.h>

void	ft_square(void *mlx, void *img, int x, int y, int size)
{
	int	x_size;
	int	i;
	int	y_size;
	int	j;

	x_size = x + size;
	y_size = y + size;
	i = 0;
	j = 0;
	while (x + i < x_size)
	{
		mlx_pixel_put(mlx, img, x, y, 0x1eb4e9);
	}
}

int	main(void)
{
	void	*img;
	void	*mlx;
	int		x = 640;
	int		y = 360;
	int		res = 0;

	mlx = mlx_init();
	img = mlx_new_window(mlx, 1920, 1080, "max");
	ft_square(mlx, img, x, y, 10);
	mlx_loop(mlx);
	return 0;
}
