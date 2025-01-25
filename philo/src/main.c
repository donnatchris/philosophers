/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 07:55:03 by christophed       #+#    #+#             */
/*   Updated: 2025/01/25 11:12:14 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;

	store_input(&rules, ac, av);
	printf("nb_philo: %d\n", rules.nb_philo);
	printf("time_to_die: %d\n", rules.time_to_die);
	printf("time_to_eat: %d\n", rules.time_to_eat);
	printf("time_to_sleep: %d\n", rules.time_to_sleep);
	printf("nb_must_eat: %d\n", rules.nb_must_eat);
	return (0);
}

