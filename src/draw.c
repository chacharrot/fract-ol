#include "fractol.h"

t_color	get_color(int iter, t_fractol *fr)
{
	t_color	color;
	double	t;

	t = (double)iter / fr->iter;
	color.color_set[0] = 0;
	color.color_set[(1 + fr->color_shift) % 3 + 1]
		= (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.color_set[(2 + fr->color_shift) % 3 + 1]
		= (int8_t)(12 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.color_set[(3 + fr->color_shift) % 3 + 1]
		= (int8_t)(7 * pow((1 - t), 3) * t * 255);
	return (color);
}

void	put_pixel(int x, int y, t_fractol *fr, int iter)
{
	int		i;
	t_color	color;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	i = (x * 4) + (y * fr->size_line);
	color = get_color(iter, fr);
	fr->addr[i] = color.color_set[3];
	fr->addr[++i] = color.color_set[2];
	fr->addr[++i] = color.color_set[1];
	fr->addr[++i] = color.color_set[0];
}

void	iter_type(int x, int y, t_fractol *fr)
{
	int			iter;
	t_complex	a;

	a.re = (fr->re_end) + (x * (2 / fr->zoom));
	a.im = fr->im_end + (HEIGHT - y) * (2 / fr->zoom);
	if (fr->type == JULIA)
		iter = iter_julia(a, fr);
	else if (fr->type == MANDELBROT)
		iter = iter_mandel(a, fr);
	else if (fr->type == BURNINGSHIP)
		iter = iter_burning_ship(a, fr);
	put_pixel(x, y, fr, iter);
}

void	draw(t_fractol *fr)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iter_type(x, y, fr);
			y++;
		}
	}
	mlx_put_image_to_window(fr->mlx, fr->window, fr->image, 0, 0);
}