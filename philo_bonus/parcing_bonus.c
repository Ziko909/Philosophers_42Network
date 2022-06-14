/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:35:59 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/13 20:41:19 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	long int		t;
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

int	parcing(int ac, char **av, t_philo *data_ptr)
{
	data_ptr->ac = ac;
	data_ptr->n_philos = ft_atoi(av[1]);
	data_ptr->t_to_die = ft_atoi(av[2]);
	data_ptr->t_to_eat = ft_atoi(av[3]);
	data_ptr->t_to_sleap = ft_atoi(av[4]);
	if (ac == 6)
	{
		data_ptr->n_must_eat = ft_atoi(av[5]);
		if (data_ptr->n_must_eat <= 0)
			return (0);
	}
	if (data_ptr->n_philos <= 0 || data_ptr->t_to_die < 0
		|| data_ptr->t_to_eat < 0 || data_ptr->t_to_sleap < 0)
		return (0);
	return (1);
}
