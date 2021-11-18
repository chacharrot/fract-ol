#include "fractol.h"

int	iter_julia(t_complex a, t_fractol *fr)
{
	int			i;
	double		tmp;

	i = 0;
	while (a.re * a.re + a.im * a.im <= 4 && i < fr->iter)
	{
		tmp = a.re * a.re - a.im * a.im + (fr->c.re);
		a.im = 2 * (a.re * a.im) + (fr->c.im);
		a.re = tmp;
		i++;
	}
	return (i);
}

int	iter_mandel(t_complex a, t_fractol *fr)
{
	int			i;
	double		tmp;
	t_complex	tmp2;

	tmp2.re = fr->c.re;
	tmp2.im = fr->c.im;
	i = 0;
	while (tmp2.re * tmp2.re + tmp2.im * tmp2.im <= 4 && i < fr->iter)
	{
		tmp = tmp2.re * tmp2.re - tmp2.im * tmp2.im + (a.re);
		tmp2.im = 2 * (tmp2.re * tmp2.im) + (a.im);
		tmp2.re = tmp;
		i++;
	}
	return (i);
}

int	iter_burning_ship(t_complex a, t_fractol *fr)
{
	int			i;
	double		tmp2;
	t_complex	tmp;

	i = 0;
	tmp.re = a.re;
	tmp.im = a.im;
	while (pow(tmp.re, 2.0) + pow(tmp.im, 2.0) <= 4 && i < fr->iter)
	{
		tmp2 = pow(tmp.re, 2.0) - pow(tmp.im, 2.0) + a.re;
		tmp.im = -2.0 * fabs(tmp.re * tmp.im) + a.im;
		tmp.re = tmp2;
		i++;
	}
	return (i);
}
