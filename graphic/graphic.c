#include "mlbx/mlx.h"

int	main(void)
{
	void	*img;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_window(mlx, 1920, 1080, "max");
	mlx_loop(mlx);
	return 0;
}
