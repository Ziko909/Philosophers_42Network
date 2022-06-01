#include "include/philo.h"




void    *routine(void *arg)
{
	t_ph_in *node = (t_ph_in *)arg;
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
void    parcing(int ac, char **av, t_philo *ptr)
{
	ptr->n_philos = ft_atoi(av[1]);
	ptr->t_to_die = ft_atoi(av[2]);
	ptr->t_to_eat = ft_atoi(av[3]);
	printf("%d\n", ptr->t_to_eat);
	ptr->t_to_sleap = ft_atoi(av[4]);
	if (ac == 6)
		ptr->n_must_eat = ft_atoi(av[5]);
}
void    ft_creat_thread(t_philo *ptr)
{
	t_ph_in *node;
	t_ph_in *temp;
	t_ph_in *head;
	
	int i = 1;
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
	while (--i > 0)
	{
		pthread_create(&head->th, NULL, routine, (void *) head);
		usleep(10);
		pthread_detach(head->th);
		head = head->next;
	}
	while(1);
}
int main(int ac, char **av)
{
	t_philo *ptr;
	if (ac == 5 || ac == 6)
	{
		ptr = malloc(sizeof(t_philo));
		parcing(ac, av, ptr);
		ft_creat_thread(ptr);
	} 

}
