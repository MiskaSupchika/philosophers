/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:57:24 by panda             #+#    #+#             */
/*   Updated: 2022/07/01 21:54:30 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int get_time()
{
    struct timeval  start;
    gettimeofday(&start, 0);
    return (start.tv_sec * 1000 + start.tv_usec / 1000);
}

void destroy_mutex(t_all *all)
{
    int i;

    i = 0;
    while(i < all->nop)
    {
        pthread_mutex_destroy(&all->fork[i]);
        i++;
    }
}

void ft_out(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	h;
	long long int	n;

	i = 0;
	h = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		h = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - 48);
    if(i > 19)
        return (-1);
	return (n * h);
}

// void free_struck(t_all *all)
// {
//     int i;
    
//     i = 0;
//     while (all->philo)
//     {
//         free (all->philo[i]);
//         i++;
//     }
//     i = 0;
//     if(all->fork[i])
//     {
//         free(all->fork[i]);
//         i++;
//     }
//     free(all);
// }

void	ft_usleep(long long time)
{
	long long	now;

	now = get_time();
	while (get_time() - now < time)
		usleep(100);
}