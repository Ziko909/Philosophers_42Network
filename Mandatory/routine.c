/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:36:34 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/11 00:58:54 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

bool	taking_the_right_fork(t_ph_in *node)
{
	if (node->ptr_s->simulation_state == 0)
		return (false);
	pthread_mutex_lock(&(node->forks));
	pthread_mutex_lock(&(node->ptr_s->writing_mutex));
	printf("%ld %d has taken a fork\n", get_time_of_status(), node->id);
	pthread_mutex_unlock(&(node->ptr_s->writing_mutex));
	return (true);
}

bool	taking_the_left_fork(t_ph_in *node)
{
	if (node->ptr_s->simulation_state == 0)
		return (false);
	pthread_mutex_lock(&(node->next->forks));
	pthread_mutex_lock(&(node->ptr_s->writing_mutex));
	printf("%ld %d has taken a fork\n", get_time_of_status(), node->id);
	pthread_mutex_unlock(&(node->ptr_s->writing_mutex));
	return (true);
}

bool	eating(t_ph_in *node)
{
	if (node->ptr_s->simulation_state == 0)
		return (false);
	pthread_mutex_lock(&(node->ptr_s->writing_mutex));
	printf("%ld %d is eating\n", get_time_of_status(), node->id);
	pthread_mutex_unlock(&(node->ptr_s->writing_mutex));
	node->died = get_time_of_now();
	ft_usleep(node->ptr_s->t_to_eat);
	pthread_mutex_unlock(&(node->forks));
	pthread_mutex_unlock(&(node->next->forks));
	if (node->ptr_s->ac == 6)
		node->ptr_s->n_e++;
	return (true);
}

bool	sleeping(t_ph_in *node)
{
	if (node->ptr_s->simulation_state == 0)
		return (false);
	pthread_mutex_lock(&(node->ptr_s->writing_mutex));
	printf("%ld %d is sleeping\n", get_time_of_status(), node->id);
	pthread_mutex_unlock(&(node->ptr_s->writing_mutex));
	ft_usleep(node->ptr_s->t_to_sleap);
	return (true);
}

bool	thinking(t_ph_in *node)
{
	if (node->ptr_s->simulation_state == 0)
		return (false);
	pthread_mutex_lock(&(node->ptr_s->writing_mutex));
	printf("%ld %d is thinking\n", get_time_of_status(), node->id);
	pthread_mutex_unlock(&(node->ptr_s->writing_mutex));
	return (true);
}
