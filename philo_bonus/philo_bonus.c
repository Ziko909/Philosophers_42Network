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

bool	waiting_for_my_childs(t_philo *data_ptr)
{
	int	status;

	while (true)
	{
		if (waitpid(-1, &status, NULL) == -1)
			return (false);
		if (status == EXIT_FAILURE)
			if (kill(0, SIGKILL) == -1)
				return (false);
	}
	ft_cleaning_of_memmory(data_ptr);
	return (true);
}

bool	creat_child_processes(t_philo *data_ptr)
{
	int	i;

	i = 1;
	data->pid_table = (int *) malloc(data_ptr->n_philos * sizeof(int));
	if (!data->pid_table)
		return (false);
	while (i <= data->ptr->n_philos)
	{
		data_ptr->pid_table[i - 1] = fork();
		if (data_ptr->pid_table[i - 1] == -1)
			return (false);
		data_ptr->id = i;
		if (!data_ptr->pid_table[i])
			child_process_work(data_ptr);
		else
			i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
    t_philo		*data_ptr;

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
	}
	return (0);
}
