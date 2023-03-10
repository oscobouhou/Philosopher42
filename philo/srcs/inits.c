/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 00:48:20 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/02 04:13:09 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_gen *general)
{
	int		i;

	i = -1;
	general->is_dead = 0;
	while (++i < general->n_philo)
	{
		general->philo[i].id = i + 1;
		general->philo[i].lfork = i;
		general->philo[i].last_eat = 0;
		general->philo[i].rfork = i + 1;
		general->philo[i].n_tt_e = general->number_philo_eat;
		if (i + 1 == general->n_philo)
			general->philo[i].rfork = 0;
		general->philo[i].general = general;
	}
}

void	*init_mutex(t_gen *general)
{
	int		i;

	i = -1;
	general->forks = malloc(sizeof(pthread_mutex_t) * general->n_philo);
	if (!general->forks)
		return (set_free(general), NULL);
	while (++i < general->n_philo)
		pthread_mutex_init(&(general->forks[i]), NULL);
	general->check_meal = malloc(sizeof(pthread_mutex_t) * general->n_philo);
	if (!general->check_meal)
		return (set_free(general), NULL);
	i = -1;
	while (++i < general->n_philo)
		pthread_mutex_init(&(general->check_meal[i]), NULL);
	pthread_mutex_init(&(general->write), NULL);
	pthread_mutex_init(&(general->check_rot), NULL);
	pthread_mutex_init(&(general->check_death), NULL);
	return (NULL);
}

t_gen	*init_simulation(char **av)
{
	t_gen	*general;

	general = malloc(sizeof(t_gen));
	if (!general)
		return (set_free(general), NULL);
	general->n_philo = ft_atoi(av[1]);
	general->tt_d = ft_atoi(av[2]);
	general->tt_e = ft_atoi(av[3]);
	general->tt_s = ft_atoi(av[4]);
	general->round_of_table = 0;
	general->philo = malloc(sizeof(t_philo) * general->n_philo);
	if (!general->philo)
		return (NULL);
	if (av[5])
		general->number_philo_eat = ft_atoi(av[5]);
	else
		general->number_philo_eat = -1;
	general->is_dead = 0;
	init_mutex(general);
	init_philos(general);
	return (general);
}
