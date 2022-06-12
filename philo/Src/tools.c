/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:10:23 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/12 16:58:25 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

bool	philo_died(t_ph_in *node, time_t died_time)
{
	node->ptr_s->simulation_state = 0;
	ft_usleep(42);
	printf("%ld %d died\n", died_time, node->id);
	return (true);
}

void	ft_unlock_mutex(t_ph_in *node)
{
	pthread_mutex_unlock(&node->forks);
}
