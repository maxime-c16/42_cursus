#include <mlx.h>
#include <math.h>

void AffichePixel(void *mlx, void *img, int x, int y, int x_centre, int y_centre)
{
	mlx_pixel_put(mlx, img, x_centre + x, y_centre + y, 0x7418AB);
	mlx_pixel_put(mlx, img, x_centre + x, y_centre - y, 0x7418AB);
	mlx_pixel_put(mlx, img, x_centre - x, y_centre + y, 0x7418AB);
	mlx_pixel_put(mlx, img, x_centre - x, y_centre - y, 0x7418AB);
	mlx_pixel_put(mlx, img, x_centre + y, y_centre + x, 0x7418AB);
	mlx_pixel_put(mlx, img, x_centre + y, y_centre - x, 0x7418AB);
	mlx_pixel_put(mlx, img, x_centre - y, y_centre + x, 0x7418AB);
	mlx_pixel_put(mlx, img, x_centre - y, y_centre - x, 0x7418AB);
}

void	ft_cercle(void *mlx, void *img, int r, int x_center, int y_center)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = (5 - r) / 4;
	mlx_pixel_put(mlx, img, x_center, y_center, 0x7418AB);
	while (x < y)
	{
		if (d < 0)
			d += x + x + 3;
		else
		{
			d += x + x - y - y + 5;
			y--;
		}
		x++;
		AffichePixel(mlx, img, x, y, x_center, y_center);
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
	while (x < 1280)
	
	mlx_loop(mlx);
	return 0;
}
