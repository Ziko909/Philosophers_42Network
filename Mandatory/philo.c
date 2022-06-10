/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:11:01 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/10 18:59:28 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

void	*routine(void *arg)
{
	t_ph_in	*node;

	node = (t_ph_in *)arg;
	if (!(node->id % 2))
		usleep(100);
	node->died = get_time_of_now();
	while (1)
	{
		taking_the_right_fork(node);
		taking_the_left_fork(node);
		eating(node);
		sleeping(node);
		thinking(node);
	}
	return (NULL);
}

t_ph_in	*creat_thread(t_ph_in *node)
{
	t_ph_in	*tmp;
	int		n_philos;

	tmp = node;
	n_philos = tmp->ptr_s->n_philos;
	if (!tmp)
		return (NULL);
	while (n_philos-- > 0)
	{
		if (pthread_create(&tmp->th, NULL, routine, (void *) tmp))
			return (NULL);
		if (pthread_detach(tmp->th))
			return (NULL);
		tmp = tmp->next;
	}
	return (node);
}

t_ph_in	*set_of_philo_info(t_philo *ptr)
{
	t_ph_in	*node;
	t_ph_in	*temp;
	t_ph_in	*head;
	int		i;

	i = 0;
	ptr->n_e = 0;
	node = malloc(sizeof(t_ph_in));
	if (!node)
		return (NULL);
	head = node;
	while (++i <= ptr->n_philos)
	{
		node->id = i;
		temp = node;
		if (i < ptr->n_philos)
			node->next = malloc(sizeof(t_ph_in));
		else
			node->next = head;
		node = node->next;
		if (!node)
			return (NULL);
		temp->next = node;
		temp->ptr_s = ptr;
		if (pthread_mutex_init(&(temp->forks), NULL))
			return (NULL);
	}
	return (head);
}

bool	check_if_dead(t_ph_in *node)
{
	t_ph_in	*tmp;
	time_t	died_time;

	tmp = node;
	if (!tmp)
		return (false);
	while (tmp)
	{
		if (get_time_of_now() - tmp->died >= tmp->ptr_s->t_to_die)
		{
			died_time = get_time_of_status();
			if (pthread_mutex_lock(&(tmp->ptr_s->writing_mutex)))
				return (false);
			printf("%ld %d died\n", died_time, tmp->id);
			break ;
		}
		if (tmp->ptr_s->ac == 6
			&& tmp->ptr_s->n_e
			== (tmp->ptr_s->n_philos * tmp->ptr_s->n_must_eat))
		{
			if (pthread_mutex_lock(&(tmp->ptr_s->writing_mutex)))
				return (false);
			break ;
		}
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_philo	*ptr;

	if (ac == 5 || ac == 6)
	{
		ptr = malloc(sizeof(t_philo));
		if (!parcing(ac, av, ptr))
			return (0);
		if (pthread_mutex_init(&(ptr->writing_mutex), NULL))
			return (0);
		if (check_if_dead(creat_thread(set_of_philo_info(ptr))) == false)
			return (0);
	}
}
