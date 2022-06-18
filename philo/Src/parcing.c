/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:10:45 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/12 01:04:16 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

time_t	ft_atoi(const char *str)
{
	time_t			t;
	int				i;
	int				signe;

	i = 0;
	t = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == '-')
			signe *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		t = t * 10 + str[i++] - 48;
	if (str[i] && !ft_isdigit(str[i]))
		return (-1);
	return (t * signe);
}

int	parcing(int ac, char **av, t_ph_in *head)
{
	head->ptr_s->ac = ac;
	head->ptr_s->n_philos = ft_atoi(av[1]);
	head->ptr_s->t_to_die = ft_atoi(av[2]);
	head->ptr_s->t_to_eat = ft_atoi(av[3]);
	head->ptr_s->t_to_sleap = ft_atoi(av[4]);
	if (ac == 6)
	{
		head->ptr_s->n_must_eat = ft_atoi(av[5]);
		if (head->ptr_s->n_must_eat <= 0)
			return (0);
	}
	if (head->ptr_s->n_philos <= 0 || head->ptr_s->t_to_die < 0
		|| head->ptr_s->t_to_eat < 0 || head->ptr_s->t_to_sleap < 0)
		return (0);
	return (1);
}
