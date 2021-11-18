#ifndef FRACTOL_H

# define FRACTOL_H

# include"../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <math.h>

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

# define WIDTH		900
# define HEIGHT		600

# define JULIA			1
# define MANDELBROT		2
# define BURNINGSHIP	3

# define MIN_ITER	40
# define MAX_ITER	10000

typedef	struct		s_color
{
	int8_t	color_set[4];
}					t_color;


typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_fractol
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

# define YEL		"\e[32m"
# define MAG		"\e[33m"
# define BOLD		"\e[1m\e[4m"
# define CLR		"\e[0m"
# define TABS		"\t\t  "

# define USG_ERR	YEL "\n\tUsage:" MAG " ./fractol" YEL " [option]\n\n"	\
					MAG "\tAvailable options:\n" YEL						\
					TABS "mandel - Mandelbrot\n"								\
					TABS "julia - Julia set\n"								\
					TABS "burnship - Burning ship\n"							\

# define CONTROLS	"\n\t\t" YEL BOLD "Controls\n\n" CLR					\
					YEL "\tMove" MAG "\t\tUp/Down/Left/Right\n"				\
					YEL "\tZoom" MAG "\t\tZ/X, Mouse wheel\n"				\
					YEL "\tFix julia" MAG "\tF\n"							\
					YEL "\tColor shift" MAG "\tC\n"							\
					YEL "\tModify iters" MAG "\tI/U\n" CLR

int			iter_julia(t_complex a, t_fractol *fr);
int			iter_mandel(t_complex a, t_fractol *fr);
int			iter_burning_ship(t_complex a, t_fractol *fr);
void		exit_str(const char *str);
void		draw(t_fractol *fr);
int			ft_strcmp(char *s1, const char *s2);
int			mouse_move(int mx, int my, t_fractol *fr);
int			mouse_wheel(int key, int mx, int my, t_fractol *fr);
int			key_handler(int key, t_fractol *fr);

#endif