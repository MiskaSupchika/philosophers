/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:57:55 by panda             #+#    #+#             */
/*   Updated: 2022/06/23 15:34:59 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*process(void *data)
{
    t_philo	*philo;
    philo = (t_philo *)data;
    printf("%lld %d", get_time() - philo->time_to_eat, philo->id, "ggd");

}

void printf_info(t_all *all, char *str)
{
    
    printf("%lld %d", get_time() - all->time_to_eat, all->philo->id, str);
}

void apropriation(t_all *all)
{
    int i;

    i = 0;
    while(i < all->nop)
    {
        all->philo[i].id = i;
        if(i < all->nop - 1)
            all->philo[i].right_fork = i + 1;
        else 
            all->philo[i].right_fork = 0;
        all->philo[i].left_fork = i;
        all->philo[i].time_to_die = all->time_to_die;
        all->philo[i].time_to_eat = all->time_to_eat;
        all->philo[i].time_to_sleep = all->time_to_sleep;
        all->philo[i].count_eat = 0;
    }
    init_fork(all);
}

void init_fork(t_all *all)
{
    int i;

    i = 0;
    while(i < all->nop)
    {
        pthread_mutex_init(&all->fork[i], NULL);
        i++;
    }
}

void memory(t_all *all)
{
    all->fork = malloc(sizeof(pthread_mutex_t) * all->nop);
    if(!all->fork)
        ft_err("no memory allocated");
    all->philo = malloc(sizeof(t_philo) * all->nop);
    if(!all->philo)
       ft_err("no memory allocated"); 
}

void init(t_all *all)
{
    int i;
    int status;
    pthread_t threads[all->nop];
    
    i = 0;
    memory(all);
    //pthread_mutex_init(&all->waiter, NULL);
    //apropriation(all);
    while (i < all->nop)
    {
        status = pthread_create(&threads[i], NULL, process, &all->philo[i]);
        if (status != 0)
            ft_err("thread creation error");
        i++;
    }
}


int main(int argc, char **argv)
{
    t_all all;
    int i;
    
    if (argc != 5 && argc != 6)
        ft_err("Wrong arguments");
    i = 0;
    while(++i < argc)
    {
        if(!(ft_atoi(argv[i])))
            ft_err("Arguments are not valid");
    }
    write(1, "afef\n", 7);
    
    all.nop = ft_atoi(argv[1]);
    printf( "%d\n", all.nop);
    if(all.nop == 1)
        ft_err("He's dead");
    all.time_to_die = ft_atoi(argv[2]);
    printf( "%d\n", all.time_to_die);
    all.time_to_eat = ft_atoi(argv[3]);
    all.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        all.meals = ft_atoi(argv[5]);
    else
        all.meals = 0;
    if(all.nop <= 0 || all.time_to_die <= 0|| all.time_to_eat <= 0 || all.time_to_sleep <= 0 || all.meals <= 0)
        ft_err("stuffy");
    write(1, "jhkjgdef\n", 10);
    write(1, "afef\n", 7);
    //init(&all);
    return (0);
}
