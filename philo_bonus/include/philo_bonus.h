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
#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <sys/time.h>
# include <libc.h>
# include <stdbool.h>
# include <semaphore.h>

typedef struct philo{
	pthread_t		th;
	time_t			died;
	time_t			t_to_die;
	time_t			t_to_eat;
	time_t			t_to_sleap;
	int				*pid_table;
	int				id;
	int				n_philos;
	int				ac;
	int				n_e;
	int				simulation_state;
	long			n_must_eat;
	sem_t			*sph;
	sem_t			*p_sph;
}t_philo;

//main process functions
bool	creat_child_processes(t_philo *data_ptr);
bool	waiting_for_my_childs(t_philo *data_ptr);
int		ft_kill_childs(t_philo *data_ptr, int died_pid);
// parcing functions
int		parcing(int ac, char **av, t_philo *data_ptr);
time_t	ft_atoi(const char *str);
int		ft_isdigit(int c);
// child process functions
void	child_process_work(t_philo *data_ptr);
void	check_if_dead(t_philo *data_ptr);
void	philo_died(t_philo *data_ptr, time_t died_time);
// routine
bool	taking_the_right_fork(t_philo *data_ptr);
bool	taking_the_left_fork(t_philo *data_ptr);
bool	eating(t_philo *data_ptr);
bool	sleeping(t_philo *data_ptr);
bool	thinking(t_philo *data_ptr);
// memory management functions
t_philo	*initialize_data(t_philo *data_ptr);
int		ft_cleaning_of_memmory(t_philo *data_ptr);
// Simulation Time Functions
time_t	get_time_of_status(void);
time_t	get_time_of_now(void);
void	ft_usleep(time_t sleep_time);
#endif
