#include "fractol.h"

static int	check_arg(char *av, t_fractol *fr)
{
	fr->type = 0;
	if (!(ft_strcmp(av, "julia")))
		fr->type = JULIA;
	else if (!(ft_strcmp(av, "mandel")))
		fr->type = MANDELBROT;
	else if (!(ft_strcmp(av, "bship")))
		fr->type = BURNINGSHIP;
	if (!fr->type)
		return (1);
	return (0);
}

static void	set_fr(t_fractol *fr)
{
	fr->zoom = HEIGHT / 2;
	fr->re_end = -3;
	fr->im_end = -2;
	fr->move = 0.1;
	fr->iter = MIN_ITER;
	fr->julia_fix = true;
	fr->color_shift = 0;
	fr->c.re = 0;
	fr->c.im = 0;
}

static t_fractol	*fractol_set(void)
{
	t_fractol	*fr;

	fr = (t_fractol *)malloc(sizeof(*fr));
	if (!fr)
		exit_str("malloc error");
	fr->mlx = mlx_init();
	fr->window = mlx_new_window(fr->mlx, WIDTH, HEIGHT, "fractol");
	fr->image = mlx_new_image(fr->mlx, WIDTH, HEIGHT);
	fr->addr = mlx_get_data_addr(fr->image, &(fr->bpp),
			&(fr->size_line), &(fr->endian));
	if (!fr->mlx || !(fr->window) || !(fr->image) || !fr->addr)
		exit_str("mlx error");
	set_fr(fr);
	return (fr);
}

int	main(int argc, char **argv)
{
	t_fractol	*fr;

	if (argc != 2)
		exit_str(USG_ERR);
	fr = fractol_set();
	if (!fr)
		exit_str("init error");
	if (argc == 2)
	{
		if (check_arg(argv[1], fr))
			exit_str(USG_ERR);
		printf("%s", CONTROLS);
		draw(fr);
		mlx_hook(fr->window, 2, 5, key_handler, fr);
		mlx_hook(fr->window, 4, (1L << 2), mouse_wheel, fr);
		mlx_hook(fr->window, 6, (1L << 6), mouse_move, fr);
		mlx_loop(fr->mlx);
	}
	return (0);
}