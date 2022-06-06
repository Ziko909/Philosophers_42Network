/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:04 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/06 00:55:02 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t  get_time_of_status(void)
{
    static time_t   f_time;
    static int      i;
    time_t          s_time;

    struct timeval  tv;
    gettimeofday(&tv, NULL);
    if (!i)
    {
        f_time = (tv.tv_sec * 1000  + tv.tv_usec / 1000);
        i = 1;
        return (0);
    }
    else
        s_time =  (tv.tv_sec * 1000  + tv.tv_usec / 1000);
    return (s_time - f_time);
}

time_t  get_time_of_now(void)
{
    struct timeval  tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void    ft_usleep(time_t sleep_time)
{
    time_t  starting;
    starting = get_time_of_now();

    while (sleep_time + starting > get_time_of_now())
            usleep(50);    
}