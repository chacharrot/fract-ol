#include "fractol.h"

void	exit_str(const char *str)
{
	printf("%s\n", str);
	exit(0);
}

int	ft_strcmp(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	print_msg(int i)
{
	if (i == USG_ERR)
	{
		printf("\n\tUsage: ./fractol [option]\n\n");
		printf("\tAvailable options:\n");
		printf("\t\tmandel - Mandelbrot\n");
		printf("\t\tjulia - Julia set\n");
		printf("\t\tbship - Burning ship\n");
		exit (0);
	}
	else if (i == CONTROLS)
	{
		printf("\n\t\t" "Controls\n\n");
		printf("\tMove" "\t\tUp/Down/Left/Right\n");
		printf("\tZoom" "\t\tZ/X, Mouse wheel\n");
		printf("\tFix julia" "\tF\n");
		printf("\tColor shift" "\tC\n");
		printf("\tModify iters" "\tI/U\n");
	}
}
