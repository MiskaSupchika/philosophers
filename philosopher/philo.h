
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 02:48:45 by rburner           #+#    #+#             */
/*   Updated: 2022/01/12 06:04:02 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <stdbool.h>


typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long int	last_eat; 
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	struct s_all	*all;

}	t_philo;

typedef struct s_all
{
	int				nop;			//количество философов
	int				time_to_die;	//через сколько умрет
	int				time_to_eat;	//время на еду
	int				time_to_sleep;	//время вр сне
	int				meals;			//количество перекусов
	long long int	start_time;
	bool			death_flag;	
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	waiter;
}			t_all;


long long int	get_time();
void			destroy_mutex(t_all *all);
void			ft_out(char *str);
int				ft_atoi(const char *str);
void			ft_usleep(long long time);

void			*process(void *data);
void			apropriation(t_all *all);
void			init_fork(t_all *all);
void			memory(t_all *all);
void			init(t_all *all);

void			printf_info(t_philo *philo, char *str);
int				eating(t_all *all, t_philo *philo);
void			sleeping(t_all *all, t_philo *philo);
void			thinking(t_all *all, t_philo *philo);


#endif 