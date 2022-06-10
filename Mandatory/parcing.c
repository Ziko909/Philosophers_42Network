/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:14:02 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/10 13:17:50 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

int	parcing(int ac, char **av, t_philo *ptr)
{
	ptr->ac = ac;
	ptr->n_philos = ft_atoi(av[1]);
	ptr->t_to_die = ft_atoi(av[2]);
	ptr->t_to_eat = ft_atoi(av[3]);
	ptr->t_to_sleap = ft_atoi(av[4]);
	if (ac == 6)
	{
		ptr->n_must_eat = ft_atoi(av[5]);
		if (ptr->n_must_eat <= 0)
			return (0);
	}
	if (ptr->n_philos <= 0 || ptr->t_to_die <= 0
		|| ptr->t_to_eat <= 0 || ptr->t_to_sleap <= 0)
		return (0);
	return (1);
}
