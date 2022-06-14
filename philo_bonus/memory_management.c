/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:27:28 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/13 20:37:01 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_philo	*initialize_data(t_ph_in *data_ptr)
{
	data_ptr = malloc(sizeof(t_philo));
	if (!data->ptr_s)
		return (NULL);
	data_ptr->pid_table = NULL;
	data_ptr->simulation_state = 1;
	return (data_ptr);
}

int	ft_cleaning_of_memmory(t_philo *data_ptr)
{
	if (data_ptr->pid_table)
		free(data_ptr->pid_table);
	if (data_ptr)
		free(data_ptr);
	return (1);
}
