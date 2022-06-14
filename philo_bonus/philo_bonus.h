/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:11:45 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/13 15:42:34 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>
# include <libc.h>
# include <stdbool.h>

typedef struct philo{
	pthread_t		th;
	time_t			died;
	int				*pid_table;
	int				id;
	int				n_philos;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleap;
	int				n_must_eat;
	int				ac;
	int				n_e;
	int				n_of_alloc;
	int				simulation_state;
}t_philo;

// parcing Functions
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		parcing(int ac, char **av, t_philo *data_ptr);
// main_thread Functions
t_ph_in	*set_of_philo_info(t_philo *data_ptr);
t_ph_in	*ft_creat_thread(t_philo *data_ptr);
bool	ft_check_if_dead(t_philo *data_ptr);
bool	philo_died(t_philo *data_ptr, time_t died_time);
// Time Functions 
time_t	get_time_of_status(void);
time_t	get_time_of_now(void);
void	ft_usleep(time_t sleep_time);
// Habits Functions 
void	*routine(void *arg);
bool	taking_the_right_fork(t_philo *data_ptr);
bool	taking_the_left_fork(t_philo *data_ptr);
bool	eating(t_philo *data_ptr);
bool	sleeping(t_philo *data_ptr);
bool	thinking(t_philo *data_ptr);
// memory Management Functions
t_philo	*initialize_data(t_philo *data_ptr);
int		ft_cleaning_of_memmory(t_philo *data_ptr);
#endif
