/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 07:55:03 by christophed       #+#    #+#             */
/*   Updated: 2025/01/29 13:57:04 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;
	t_dclst	**agora;
	int		n_threads;

	if (ac != 5 && ac != 6)
		error("Invalid number of arguments", NULL);
	store_input(&rules, ac, av);
	print_rules(rules);
	agora = malloc(sizeof(t_dclst *));
	if (!agora)
		error("malloc failed", NULL);
	store_philosophers(agora, rules.nb_philo, &rules);
	if (rules.nb_must_eat == -1)
		n_threads = rules.nb_philo + 1;
	else
		n_threads = rules.nb_philo + 2;
	run_simulation(agora, rules, n_threads);
	return (0);
}
