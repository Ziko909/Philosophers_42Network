/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:36:34 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/31 13:36:35 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
void	taking_the_right_fork(t_ph_in *node)
{
	pthread_mutex_lock(&(node->forks));
	printf("%ld %d has  taken the right fork\n", get_time_of_status(), node->id);
}

void	taking_the_left_fork(t_ph_in *node)
{
	struct	timeval  tv;
	if((node->id % 2))
		pthread_mutex_lock(&(node->next->forks));
	else
		pthread_mutex_lock(&(node->prev->forks));
	printf("%ld %d has  taken the left fork\n", get_time_of_status(), node->id);
	gettimeofday(&tv, NULL);
}

void	eating(t_ph_in *node)
{
	printf("%ld %d is eating\n",get_time_of_status(), node->id);
	node->died = get_time_of_now();
	usleep (node->ptr_s->t_to_eat * 1000);
	pthread_mutex_unlock(&(node->forks));
	if((node->id % 2))
		pthread_mutex_unlock(&(node->next->forks));
	else
		pthread_mutex_unlock(&(node->prev->forks));
}

void	sleeping(t_ph_in *node)
{
	printf("%ld %d  is sleeping\n",get_time_of_status(), node->id);
	usleep (node->ptr_s->t_to_sleap * 1000);
}

void	thinking(t_ph_in *node)
{
	printf("%ld %d  is thinking\n",get_time_of_status(), node->id);
}