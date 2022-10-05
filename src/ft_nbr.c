/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:55:54 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/04 20:16:38 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/**
 *	KO - parse spaces
 *	OK - has any thing beyond of + - integer
 *	OK - parse zeros -> yes
 *	OK - is_integer?
 *	OK - is_valid_range?
 * 	printf("INT CANDIDATE: %ld\n", int_candidate);
 **/
int	is_integer(char *nbr, int signal)
{
	long	int_candidate;

	if (ft_strlen(nbr) > INT_MAX_LEN)
		return (false);
	int_candidate = signal * ft_atol(nbr);
	if (int_candidate < INT_MIN || int_candidate > INT_MAX)
		return (false);
	return (true);
}

/**
 * TODO: Reuse parsing logic:
 * 			- convert nbr to remove duplicates
 * 			- normalize data to be used within sorting algorithms
 * TODO: Refactor ft_atol to parse more than one +- signals
 **/
int	is_number(char *nbr, t_ps *ps)
{
	int	i;
	int	j;
	int	signal;

	i = 0;
	signal = 1;
	while (ft_isspace(nbr[i]))
		i++;
	while (is_plus_or_minus(nbr[i]))
		if (nbr[i++] == '-')
			signal *= -1;
	while (is_zero(nbr[i]))
		i++;
	j = i;
	while (nbr[j])
		if (!ft_isdigit(nbr[j++]))
			return (set_error(e_input_must_be_integers, ps));
	if (!is_integer(&nbr[i], signal))
		return (set_error(e_invalid_nbr_len, ps));
	return (true);
}
