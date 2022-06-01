#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>
# include <libc.h>
typedef struct philo{
     int  n_philos;
     int  t_to_die;
     int  t_to_eat;
     int  t_to_sleap;
     int  n_must_eat;
}t_philo;

typedef struct philos_info{
     pthread_t th;
     int  id;
     int  n_e;
     time_t  died;
     pthread_mutex_t forks;
     t_philo         *ptr_s;
     struct philos_info *next;
     struct philos_info *prev;
}t_ph_in;

//helpful Functions
int  ft_atoi(const char *str);
int  ft_isdigit(int c);

// parcing Functions
void      parcing(int ac, char **av, t_philo *ptr);
time_t    get_time(void);

// routine function
void    *routine(void *arg);
// habits Functions
void taking_the_right_fork(t_ph_in *node);
void taking_the_left_fork(t_ph_in *node);
void eating(t_ph_in *node);
void sleeping(t_ph_in *node);
#endif
