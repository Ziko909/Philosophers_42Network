#include "../include/philo.h"

void    *routine(void *arg)
{
	t_ph_in *node = (t_ph_in *)arg;
	if (!(node->id % 2))
		usleep(500);
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
int	parcing(int ac, char **av, t_philo *ptr)
{
	ptr->ac = ac;
	ptr->n_philos = ft_atoi(av[1]);
	ptr->t_to_die = ft_atoi(av[2]);
	ptr->t_to_eat = ft_atoi(av[3]);
	ptr->t_to_sleap = ft_atoi(av[4]);
	if (ac == 6)
	{
		ptr->n_must_eat = ft_atoi(av[5]);
		if (ptr->n_must_eat <= 0)
			return (0);
	}
	if (ptr->n_philos <= 0 || ptr->t_to_die <= 0 ||
	 ptr->t_to_eat <= 0 || ptr->t_to_sleap <= 0)
	 return (0);
	return (1);
}
void    ft_creat_thread(t_philo *ptr)
{
	t_ph_in *node;
	t_ph_in *temp;
	t_ph_in *head;
	
	int i = 1;
	ptr->n_e = 0;
	node = malloc(sizeof(t_ph_in));
	head = node;
	while (i <=  ptr->n_philos)
	{
		node->id = i;
		temp = node;
		if (i < ptr->n_philos)
			node->next = malloc(sizeof(t_ph_in));
		else
			node->next = head;
		node = node->next;
		temp->next = node;
		node->prev = temp;
		temp->ptr_s = ptr;
		pthread_mutex_init(&(temp->forks), NULL);
		i++; 
	}
	temp = head;
	while (--i > 0)
	{
		pthread_create(&head->th, NULL, routine, (void *) head);
		pthread_detach(head->th);
		head = head->next;
	}
	while(temp)
	{
		if (temp->ptr_s->ac == 6 && temp->ptr_s->n_e == temp->ptr_s->n_philos * temp->ptr_s->n_must_eat)
		{
			pthread_mutex_lock(&(ptr->writing_mutex));
			break;
		}
		if (get_time_of_now() - temp->died > ptr->t_to_die)
		{
			pthread_mutex_lock(&(ptr->writing_mutex));
			printf("%ld %d died\n", get_time_of_status(), node->id);
			break ;
		}
	}
}
int main(int ac, char **av)
{
	t_philo *ptr;
	if (ac == 5 || ac == 6)
	{
		ptr = malloc(sizeof(t_philo));
		if (!parcing(ac, av, ptr))
			return (0);
		if (pthread_mutex_init(&(ptr->writing_mutex), NULL))
			return (0);
		ft_creat_thread(ptr);
	}
}
