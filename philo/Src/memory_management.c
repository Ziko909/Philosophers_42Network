/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:27:28 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/12 16:56:24 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_ph_in	*initialize_data(t_ph_in *head)
{
	head = malloc(sizeof(t_ph_in));
	if (!head)
		return (NULL);
	head->ptr_s = malloc(sizeof(t_philo));
	if (!head->ptr_s)
		return (NULL);
	head->ptr_s->n_of_alloc = 1;
	head->ptr_s->n_e = 0;
	head->ptr_s->simulation_state = 1;
	return (head);
}

int	ft_cleaning_of_memmory(t_ph_in *head)
{
	int		n_of_alloc;
	t_ph_in	*tmp;

	n_of_alloc = head->ptr_s->n_of_alloc;
	free(head->ptr_s);
	while (--n_of_alloc)
	{
		tmp = head;
		pthread_mutex_destroy(&tmp->forks);
		head = head->next;
		free (tmp);
	}
	return (1);
}
