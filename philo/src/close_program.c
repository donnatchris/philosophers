/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:47:40 by christophed       #+#    #+#             */
/*   Updated: 2025/02/10 12:15:12 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Function to print an error message and free the agora list
void	error(char *message, t_rules *rules, t_dclst **agora)
{
	printf("Error\n%s\n", message);
	free_and_exit(rules, agora, 1);
}

// Function to exit the program and free memory
void	free_and_exit(t_rules *rules, t_dclst **agora, int status)
{
	t_philo	*first_philo;

	if (rules)
	{
		if (rules->log_mutex_init)
			pthread_mutex_destroy(&rules->log_mutex);
		if (rules->run_mutex_init)
			pthread_mutex_destroy(&rules->run_mutex);
	}
	if (agora)
	{
		first_philo = (t_philo *)(*agora)->data;
		destroy_forks(first_philo->left_fork, rules->nb_philo);
		destroy_philo_mutexes(agora);
		dclst_clear(agora);
	}
	exit(status);
}

// Function to destroy the mutexes of the philosophers
void	destroy_philo_mutexes(t_dclst **agora)
{
	t_dclst	*current;
	t_philo	*philo;

	if (agora == NULL || *agora == NULL)
		return ;
	current = *agora;
	while (current != NULL)
	{
		philo = (t_philo *)current->data;
		if (philo->last_meal_init)
			pthread_mutex_destroy(&philo->last_meal_mutex);
		if (philo->n_meal_init)
			pthread_mutex_destroy(&philo->n_meals_mutex);
		current = current->next;
		if (current == *agora)
			break ;
	}
}

// Function to destroy the forks
void	destroy_forks(pthread_mutex_t *forks, int nb_forks)
{
	int	i;

	i = 0;
	while (i < nb_forks)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}
