#ifndef FRACTOL_H

# define FRACTOL_H

# include"../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <math.h>

# ifdef __linux__
#  define KB_ESC		65307
#  define KB_X			120
#  define KB_Z			122
#  define KB_UP			65362
#  define KB_DOWN		65364
#  define KB_LEFT		65361
#  define KB_RIGHT		65363
#  define KB_I			105
#  define KB_U			117
#  define KB_F			102
#  define KB_C			99
#  define MWHEELUP		4
#  define MWHEELDN		5
# else
#  define KB_ESC		53
#  define KB_X			18 //macos 1
#  define KB_Z			19 //macos 2
#  define KB_UP			126
#  define KB_DOWN		125
#  define KB_LEFT		123
#  define KB_RIGHT		124
#  define KB_I			20 //macos 3
#  define KB_U			21 //macos 4
#  define KB_F			23 //macos 5
#  define KB_C			22 //macos 6
#  define MWHEELUP		4
#  define MWHEELDN		5
# endif
# define WIDTH			900
# define HEIGHT			600

# define JULIA			1
# define MANDELBROT		2
# define BURNINGSHIP	3

# define MIN_ITER		40
# define MAX_ITER		10000

# define USG_ERR		1
# define CONTROLS		2

typedef struct s_color
{
	int8_t	color_set[4];
}				t_color;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractol
{
	void			*mlx;
	void			*window;
	int				type;
	void			*image;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
	double			re_end;
	double			im_end;
	int				color_shift;
	int				iter;
	double			zoom;
	double			move;
	t_complex		c;
	t_complex		mpos;
	bool			julia_fix;
}					t_fractol;

int			iter_julia(t_complex a, t_fractol *fr);
int			iter_mandel(t_complex a, t_fractol *fr);
int			iter_burning_ship(t_complex a, t_fractol *fr);
void		exit_str(const char *str);
void		draw(t_fractol *fr);
int			ft_strcmp(char *s1, const char *s2);
int			mouse_move(int mx, int my, t_fractol *fr);
int			mouse_wheel(int key, int mx, int my, t_fractol *fr);
int			key_handler(int key, t_fractol *fr);
void		print_msg(int i);

#endif