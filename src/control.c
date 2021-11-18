#include "fractol.h"

static void	zoom(t_fractol *fr, int key)
{
	double		d;
	t_complex	corr;

	d = 2 * HEIGHT / fr->zoom;
	corr.re = fr->re_end + ((float)fr->mpos.re / WIDTH) * d * 1.5;
	corr.im = fr->im_end + ((HEIGHT - (float)fr->mpos.im) / HEIGHT) * d;
	if (key == KB_X || key == MWHEELUP)
	{
		fr->zoom *= 1.05;
		fr->move *= 0.95;
		if (fr->iter < MAX_ITER)
			fr->iter += 2;
	}
	else
	{
		fr->zoom *= 0.95;
		fr->move *= 1.05;
		if (fr->iter > MIN_ITER)
			fr->iter -= 2;
	}
	d = 2 * HEIGHT / fr->zoom;
	fr->re_end = corr.re - ((float)fr->mpos.re / WIDTH) * d * 1.5;
	fr->im_end = corr.im - ((HEIGHT - (float)fr->mpos.im) / HEIGHT) * d;
}

int	mouse_wheel(int key, int mx, int my, t_fractol *fr)
{
	if (key == MWHEELUP || key == MWHEELDN)
	{
		fr->mpos.re = mx;
		fr->mpos.im = my;
		zoom(fr, key);
		draw(fr);
	}
	return (0);
}

int	mouse_move(int mx, int my, t_fractol *fr)
{
	if (fr->type == JULIA && fr->julia_fix)
	{
		fr->c.re = 4 * ((float)mx / WIDTH - 0.5);
		fr->c.im = 4 * ((float)(HEIGHT - my) / HEIGHT - 0.5);
		draw(fr);
	}
	fr->mpos.re = mx;
	fr->mpos.im = my;
	return (0);
}

static void	move(t_fractol *fr, int key)
{
	if (key == KB_RIGHT)
		fr->re_end -= fr->move;
	else if (key == KB_LEFT)
		fr->re_end += fr->move;
	else if (key == KB_UP)
		fr->im_end -= fr->move;
	else if (key == KB_DOWN)
		fr->im_end += fr->move;
}

int	key_handler(int key, t_fractol *fr)
{
	if (key == KB_ESC)
		exit_str("esc");
	else if (key == KB_X || key == KB_Z)
		zoom(fr, key);
	else if (key == KB_RIGHT || key == KB_DOWN
		||key == KB_LEFT || key == KB_UP)
		move(fr, key);
	else if (key == KB_I && (1.05 * fr->iter) < MAX_ITER)
		fr->iter *= 1.05;
	else if (key == KB_U && (0.95 * fr->iter) > 50)
		fr->iter *= 0.95;
	else if (key == KB_F)
		fr->julia_fix = !fr->julia_fix;
	else if (key == KB_C)
		fr->color_shift += 1;
	draw(fr);
	return (0);
}