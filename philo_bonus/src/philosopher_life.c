/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:25:10 by christophed       #+#    #+#             */
/*   Updated: 2025/02/07 10:16:12 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Function to simulate the life of a philosopher
void	philosopher_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		philo_think(philo);
		usleep(500);
	}
	while (1)
	{
		if (philo_eat(philo) == STOP)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
}
// Function to handle thinking
void	philo_think(t_philo *philo)
{
	write_log(philo, THINK);
}

// Function to handle eating
int	philo_eat(t_philo *philo)
{
	int	meals;
	sem_wait(philo->rules->forks_sem);
	write_log(philo, FORK);
	if (philo->rules->nb_philo == 1 || check_run(philo->rules, READ) == STOP)
	{
		sem_post(philo->rules->forks_sem);
		return (STOP);
	}
	sem_wait(philo->rules->forks_sem);
	if (check_run(philo->rules, READ) == STOP)
	{
		sem_post(philo->rules->forks_sem);
		return (STOP);
	}
	write_log(philo, FORK);
	write_log(philo, EAT);
	check_last_meal(philo, WRITE);
	usleep(philo->rules->time_to_eat * 1000);
	meals = check_n_meals(philo, WRITE);
	sem_post(philo->rules->forks_sem);
	sem_post(philo->rules->forks_sem);
	if (philo->rules->nb_must_eat != -1)
		if (meals >= philo->rules->nb_must_eat)
			return (STOP);
	return (CONTINUE);
}

// Function to handle sleeping
void	philo_sleep(t_philo *philo)
{
	write_log(philo, SLEEP);
	usleep(philo->rules->time_to_sleep * 1000);
}
