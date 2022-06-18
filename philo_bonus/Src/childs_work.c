/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:59:00 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/18 02:59:44 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo_bonus.h"

void	*routine(void *arg)
{
	t_philo	*data_ptr;

	data_ptr = (t_philo *)arg;
	if (!(data_ptr->id % 2))
		usleep(100);
	data_ptr->died = get_time_of_now();
	while (1)
	{
		if (taking_the_right_fork(data_ptr) == false)
			return (NULL);
		if (taking_the_left_fork(data_ptr) == false)
			return (NULL);
		if (eating(data_ptr) == false)
			return (NULL);
		if (sleeping(data_ptr) == false)
			return (NULL);
		if (thinking(data_ptr) == false)
			return (NULL);
	}
	return (NULL);
}

void	philo_died(t_philo *data_ptr, time_t died_time)
{
	data_ptr->simulation_state = 0;
	ft_usleep(42);
	sem_wait(data_ptr->p_sph);
	printf("%ld %d died\n", died_time, data_ptr->id);
}

void	check_if_dead(t_philo *data_ptr)
{
	time_t	died_time;

	while (true)
	{
		if (get_time_of_now() - data_ptr->died > data_ptr->t_to_die)
		{
			died_time = get_time_of_status();
			philo_died(data_ptr, died_time);
			ft_cleaning_of_memmory(data_ptr);
			exit(EXIT_FAILURE);
		}
		if (data_ptr->ac == 6
			&& data_ptr->n_e == data_ptr->n_must_eat)
		{
			data_ptr->simulation_state = 0;
			ft_usleep(2);
			ft_cleaning_of_memmory(data_ptr);
			exit(EXIT_SUCCESS);
		}
	}
}

void	child_process_work(t_philo *data_ptr)
{
	if (pthread_create(&data_ptr->th, NULL, routine, (void *)data_ptr))
	{
		ft_cleaning_of_memmory(data_ptr);
		exit(EXIT_FAILURE);
	}
	data_ptr->died = get_time_of_now();
	if (pthread_detach(data_ptr->th))
	{
		ft_cleaning_of_memmory(data_ptr);
		exit(EXIT_FAILURE);
	}
	check_if_dead(data_ptr);
}
