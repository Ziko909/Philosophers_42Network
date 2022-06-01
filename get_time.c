/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:04 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/31 17:08:11 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

time_t  get_time(void)
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