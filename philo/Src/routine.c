/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:36:34 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/12 16:58:42 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

bool	taking_the_right_fork(t_ph_in *node)
{
	pthread_mutex_lock(&(node->forks));
	if (node->ptr_s->simulation_state == 0)
		return (ft_unlock_mutex(node), false);
	printf("%ld %d has taken a fork\n", get_time_of_status(), node->id);
	return (true);
}

bool	taking_the_left_fork(t_ph_in *node)
{
	pthread_mutex_lock(&(node->next->forks));
	if (node->ptr_s->simulation_state == 0)
		return (ft_unlock_mutex(node), ft_unlock_mutex(node->next), false);
	printf("%ld %d has taken a fork\n", get_time_of_status(), node->id);
	return (true);
}

bool	eating(t_ph_in *node)
{
	if (node->ptr_s->simulation_state == 0)
		return (ft_unlock_mutex(node), ft_unlock_mutex(node->next), false);
	printf("%ld %d is eating\n", get_time_of_status(), node->id);
	node->died = get_time_of_now();
	if (node->ptr_s->ac == 6)
		node->ptr_s->n_e++;
	ft_usleep(node->ptr_s->t_to_eat);
	pthread_mutex_unlock(&(node->forks));
	pthread_mutex_unlock(&(node->next->forks));
	return (true);
}

bool	sleeping(t_ph_in *node)
{
	if (node->ptr_s->simulation_state == 0)
		return (false);
	printf("%ld %d is sleeping\n", get_time_of_status(), node->id);
	ft_usleep(node->ptr_s->t_to_sleap);
	return (true);
}

bool	thinking(t_ph_in *node)
{
	if (node->ptr_s->simulation_state == 0)
		return (false);
	printf("%ld %d is thinking\n", get_time_of_status(), node->id);
	return (true);
}
