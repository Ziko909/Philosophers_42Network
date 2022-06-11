/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:10:23 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/11 20:10:28 by zaabou           ###   ########.fr       */
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
	if (pthread_mutex_unlock(&head->ptr_s->writing_mutex))
		return (0);
	if (pthread_mutex_destroy(&(head->ptr_s->writing_mutex)))
		return (0);
	free(head->ptr_s);
	while (--n_of_alloc)
	{
		tmp = head;
		if (pthread_mutex_destroy(&tmp->forks))
			return (0);
		head = head->next;
		free (tmp);
	}
	return (1);
}
