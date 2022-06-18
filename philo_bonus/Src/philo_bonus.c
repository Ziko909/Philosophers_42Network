/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:44:25 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/14 13:18:49 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_kill_childs(t_philo *data_ptr, int died_pid)
{
	int	i;

	i = 0;
	while (i < data_ptr->n_philos)
	{
		if (data_ptr->pid_table[i] != died_pid)
		{
			if (kill(data_ptr->pid_table[i], SIGKILL) == -1)
				return (-1);
		}
		i++;
	}
	if (sem_close(data_ptr->sph) == -1)
		return (-1);
	if (sem_unlink("/eating area") == -1)
		return (-1);
	if (sem_close(data_ptr->p_sph) == -1)
		return (-1);
	if (sem_unlink("/print") == -1)
		return (-1);
	return (1);
}

bool	waiting_for_my_childs(t_philo *data_ptr)
{
	int	status;
	int	i;
	int	pid;

	i = 0;
	while (++i <= data_ptr->n_philos)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			return (false);
		if (status == 256)
		{
			if (ft_kill_childs(data_ptr, pid) == -1)
				return (false);
		}
	}
	return (true);
}

bool	creat_child_processes(t_philo *data_ptr)
{
	int	i;

	i = 1;
	data_ptr->sph = sem_open("/eating area", O_CREAT, 666, data_ptr->n_philos);
	if (data_ptr->sph == SEM_FAILED)
		return (false);
	data_ptr->p_sph = sem_open("/print", O_CREAT, 666, 1);
	if (data_ptr->p_sph == SEM_FAILED)
		return (false);
	data_ptr->pid_table = (int *) malloc(data_ptr->n_philos * sizeof(int));
	if (!data_ptr->pid_table)
		return (false);
	while (i <= data_ptr->n_philos)
	{
		get_time_of_status();
		data_ptr->pid_table[i - 1] = fork();
		if (data_ptr->pid_table[i - 1] == -1)
			return (false);
		data_ptr->id = i;
		if (!data_ptr->pid_table[i - 1])
			child_process_work(data_ptr);
		else
			i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_philo	*data_ptr;

	if (ac == 5 || ac == 6)
	{
		data_ptr = NULL;
		data_ptr = initialize_data(data_ptr);
		if (!data_ptr)
			return (1);
		if (!parcing(ac, av, data_ptr))
			return (ft_cleaning_of_memmory(data_ptr), 1);
		if (creat_child_processes(data_ptr) == false)
			return (ft_cleaning_of_memmory(data_ptr), 1);
		if (waiting_for_my_childs(data_ptr) == false)
			return (ft_cleaning_of_memmory(data_ptr), 1);
		if (ft_cleaning_of_memmory(data_ptr) == -1)
			exit (1);
		exit (0);
	}
	return (0);
}
