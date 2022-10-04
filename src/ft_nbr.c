/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:55:54 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/03 23:01:11 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_plus_or_minus(char c)
{
	return (c == '-' || c == '+');
}

int	is_zero(char c)
{
	return (c == '0');
}

/**
 *	KO - parse spaces
 *	OK - has any thing beyond of + - integer
 *	OK - parse zeros -> yes
 *	OK - is_integer?
 *	is_valid_range?
 **/
int	is_number(char *nbr, t_ps *ps)
{
	int	i;
	int	j;
	int	signal;

	i = 0;
	signal = 1;
	while (is_plus_or_minus(nbr[i]))
		if (nbr[i++] == '-')
			signal *= -1;
	while (is_zero(nbr[i]))
		i++;
	j = i;
	while (nbr[j])
		if (!ft_isdigit(nbr[j++]))
			return (set_error(e_input_must_be_integers, ps));
	return (true);
}
/**
 * static int	is_number(char *nbr, t_ps *ps)
 * {
 * 	int	i;
 * 	int	j;
 * 	int	signal;
 * 
 * 	i = -1;
 * 	signal = 1;
 * 	while (is_plus_or_minus(nbr[++i]))
 * 		if (nbr[i] == '-')
 * 			signal *= -1;
 * 	printf("i: %d, nbr: %c, signal: %d\n", i, nbr[i], signal);
 * 	while (is_zero(nbr[i]))
 * 		i++;
 * 	printf("i: %d, nbr: %c, signal: %d\n", i, nbr[i], signal);
 * 	j = i;
 * 	while (nbr[++j])
 * 		if(!ft_isdigit(nbr[j]))
 * 			return (set_error(e_input_must_be_integers, ps));
 * 	ft_putendl_fd("\nTestando is_plus_or_minus...", 1);
 * 	ft_putchar_fd(nbr[i], 1);
 * 	ft_putendl_fd("", 1);
 * 	ps->fl_error = false;
 * 	return (true);
 * }
 **/
