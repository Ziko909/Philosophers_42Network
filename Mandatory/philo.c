/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:09:41 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/11 20:09:51 by zaabou           ###   ########.fr       */
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
		if (taking_the_right_fork(node) == false)
			return (NULL);
		if (taking_the_left_fork(node) == false)
			return (NULL);
		if (eating(node) == false)
			return (NULL);
		if (sleeping(node) == false)
			return (NULL);
		if (thinking(node) == false)
			return (NULL);
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
		tmp->died = get_time_of_now();
		if (pthread_detach(tmp->th))
			return (NULL);
		tmp = tmp->next;
	}
	return (node);
}

t_ph_in	*set_of_philo_info(t_ph_in *head)
{
	t_ph_in	*node;
	t_ph_in	*temp;
	int		i;

	i = 0;
	node = head;
	while (++i <= head->ptr_s->n_philos)
	{
		node->id = i;
		temp = node;
		if (i < head->ptr_s->n_philos)
			node->next = malloc(sizeof(t_ph_in));
		else
			node->next = head;
		node = node->next;
		if (!node)
			return (NULL);
		temp->ptr_s = head->ptr_s;
		temp->ptr_s->n_of_alloc++;
		temp->next = node;
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
			tmp->ptr_s->simulation_state = 0;
			if (pthread_mutex_lock(&(tmp->ptr_s->writing_mutex)))
				return (false);
			printf("%ld %d died\n", died_time, tmp->id);
			break ;
		}
		if (tmp->ptr_s->ac == 6
			&& tmp->ptr_s->n_e
			== (tmp->ptr_s->n_philos * tmp->ptr_s->n_must_eat))
		{
			tmp->ptr_s->simulation_state = 0;
			if (pthread_mutex_lock(&(tmp->ptr_s->writing_mutex)))
				return (false);
			break ;
		}
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_ph_in		*head;

	if (ac == 5 || ac == 6)
	{
		head = NULL;
		head = initialize_data(head);
		if (!head)
			return (0);
		if (!parcing(ac, av, head))
			return (ft_cleaning_of_memmory(head), 0);
		if (pthread_mutex_init(&(head->ptr_s->writing_mutex), NULL))
			return (ft_cleaning_of_memmory(head), 0);
		if (check_if_dead(creat_thread(set_of_philo_info(head))) == false)
			return (ft_cleaning_of_memmory(head), 0);
		if (!ft_cleaning_of_memmory(head))
			return (0);
	}
	return (1);
}
