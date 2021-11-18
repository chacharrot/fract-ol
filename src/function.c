#include "fract-ol.h"

void	exit_str(const char *str)
{
	printf("%s\n", str);
	exit(0);
}

int		ft_strcmp(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
