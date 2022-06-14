/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:35:42 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/13 18:34:43 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


bool	taking_the_right_fork(t_philo *data_ptr)
{
	if (data_ptr->simulation_state == 0)
		return (false);
	printf("%ld %d has taken a fork\n", get_time_of_status(),data_ptr->id);
	return (true);
}

bool	taking_the_left_fork(t_philo *data_ptr)
{
	if (data_ptr->simulation_state == 0)
		return (false);
	printf("%ld %d has taken a fork\n", get_time_of_status(),data_ptr->id);
	return (true);
}

bool	eating(t_philo *data_ptr)
{
	if (data_ptr->simulation_state == 0)
		return (false);
	printf("%ld %d is eating\n", get_time_of_status(),data_ptr->id);
	data_ptr->died = get_time_of_now();
	ft_usleep(data_ptr->t_to_eat);
	if (data_ptr->ac == 6)
		data_ptr->n_e++;
	return (true);
}

bool	sleeping(t_philo *data_ptr)
{
	if (data_ptr->simulation_state == 0)
		return (false);
	printf("%ld %d is sleeping\n", get_time_of_status(),data_ptr->id);
	ft_usleep(data_ptr->t_to_sleap);
	return (true);
}

bool	thinking(t_philo *data_ptr)
{
	if (data_ptr->simulation_state == 0)
		return (false);
	printf("%ld %d is thinking\n", get_time_of_status(),data_ptr->id);
	return (true);
}
