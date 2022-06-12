/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:25:06 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/12 16:20:16 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>
# include <libc.h>
# include <stdbool.h>

typedef struct philo{
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

typedef struct philos_info{
	pthread_t			th;
	int					id;
	time_t				died;
	pthread_mutex_t		forks;
	t_philo				*ptr_s;
	struct philos_info	*next;
	struct philos_info	*prev;
}t_ph_in;

// parcing Functions
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		parcing(int ac, char **av, t_ph_in *head);
// main_thread Functions
t_ph_in	*set_of_philo_info(t_ph_in *head);
t_ph_in	*ft_creat_thread(t_ph_in *node);
bool	ft_check_if_dead(t_ph_in *node);
bool	philo_died(t_ph_in *node, time_t died_time);
// Time Functions 
time_t	get_time_of_status(void);
time_t	get_time_of_now(void);
void	ft_usleep(time_t sleep_time);
// Habits Functions 
void	*routine(void *arg);
bool	taking_the_right_fork(t_ph_in *node);
bool	taking_the_left_fork(t_ph_in *node);
bool	eating(t_ph_in *node);
bool	sleeping(t_ph_in *node);
bool	thinking(t_ph_in *node);
// memory Management Functions
t_ph_in	*initialize_data(t_ph_in *head);
int		ft_cleaning_of_memmory(t_ph_in *head);
// protect the data
void	ft_unlock_mutex(t_ph_in *node);
#endif
