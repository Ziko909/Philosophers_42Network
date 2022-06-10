#include "../include/philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	long int		t;
	int				i;

	i = 0;
	t = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == '-')
			exit(1);
	while (str[i] >= '0' && str[i] <= '9')
		t = t * 10 + str[i++] - 48;
	if (str[i] && !ft_isdigit(str[i]))
		exit(1);
	return (t);
}
