/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_sleep_and_think.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:39:30 by panda             #+#    #+#             */
/*   Updated: 2022/07/05 02:59:13 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void printf_info(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->all->waiter);
    
    ft_putnbr_fd(get_time() - philo->all->start_time, 1);
    write(1, "ms ", 4);
    ft_putnbr_fd(philo->id, 1);
    write(1, " ", 1);
    ft_putstr_fd(str, 2);
    if (ft_strncmp(str, "is died\n", 9) != 0)
        pthread_mutex_unlock(&philo->all->waiter);
}

int eating(t_all *all, t_philo *philo)
{
    pthread_mutex_lock(&all->fork[philo->left_fork]);
    printf_info(philo, "take fork\n");
    pthread_mutex_lock(&all->fork[philo->right_fork]);
    printf_info(philo, "take fork\n");
    printf_info(philo, "is eating\n");
    if(all->meals)
        all->meals--;
    philo->last_eat = get_time();
    ft_usleep(philo->time_to_eat);
    pthread_mutex_unlock(&all->fork[philo->left_fork]);
    pthread_mutex_unlock(&all->fork[philo->right_fork]);
}

void sleeping(t_all *all, t_philo *philo)
{
    printf_info(philo, "is sleeping\n");
    ft_usleep(philo->time_to_sleep);
}

void thinking(t_all *all, t_philo *philo)
{
    printf_info(philo, "is thinking\n");
}
