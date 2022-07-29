/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:57:55 by panda             #+#    #+#             */
/*   Updated: 2022/07/05 03:05:26 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *dead_thread(void *data)
{
    t_all *all;
    int i;
    all = (t_all *)data;
    while(true)
    {
        i = 0;
        while (i < all->nop)
        {
            if(get_time() - all->philo[i].last_eat > all->philo[i].time_to_die)
            {
                all->death_flag = 1;
                printf_info(&all->philo[i], "is died\n");
                exit(0);
            }
            i++;
        }
    }
}

void	*process(void *data)
{
    t_philo	*philo;
    t_all *all;
    int i;
    philo = (t_philo *)data;
    all = philo->all;
    i = 0;
    if (philo->id % 2 == 0)
    {
        sleeping(all, philo);
    }
    while (!all->death_flag)
    {
        if(eating(all, philo))
            return NULL;
        sleeping(all, philo);
        thinking(all, philo);
    }
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
        all->philo[i].all = all;
        all->philo[i].last_eat = all->start_time;
        i++;
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
        ft_out("no memory allocated\n");
    all->philo = malloc(sizeof(t_philo) * all->nop);
    if(!all->philo)
       ft_out("no memory allocated\n");
}

void init(t_all *all)
{
    int i;
    int status;
    pthread_t threads[all->nop];
    
    memory(all);
    pthread_mutex_init(&all->waiter, NULL);
    all->start_time = get_time();
    apropriation(all);
    i = -1;
    while (++i < all->nop)
    {
        status = pthread_create(&threads[i], NULL, process, &all->philo[i]);
        if (status != 0)
            ft_out("thread creation error\n");
    }
    dead_thread(all);
    i = 0;
    while (i < all->nop)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
}


int main(int argc, char **argv)
{
    t_all all;
    int i;
    
    if (argc != 5 && argc != 6)
        ft_out("Wrong arguments\n");
    i = 0;
    while(++i < argc)
    {
        if((ft_atoi(argv[i]) < 0))
            ft_out("Arguments are not valid\n");
    }    
    all.nop = ft_atoi(argv[1]);
    if(all.nop == 1)
        ft_out("He's dead\n");
    all.time_to_die = ft_atoi(argv[2]);
    all.time_to_eat = ft_atoi(argv[3]);
    all.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        all.meals = ft_atoi(argv[5]);
    else
        all.meals = 0;
    if(all.nop <= 0 || all.time_to_die <= 0|| all.time_to_eat <= 0 || all.time_to_sleep <= 0 || all.meals < 0)
        ft_out("stuffy\n");
    all.death_flag = 0;
    init(&all);
    return (0);
}
