/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:55:54 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/06 23:27:33 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_nbr_info	get_nbr_info(char *nbr)
{
	t_nbr_info	ret;
	int			signal;
	int			i;

	i = 0;
	signal = 1;
	while (ft_isspace(nbr[i]))
		i++;
	while (is_plus_or_minus(nbr[i]))
		if (nbr[i++] == '-')
			signal *= -1;
	while (is_zero(nbr[i]))
		i++;
	ret.offset = i;
	ret.signal = signal;
	return (ret);
}

// printf("INT CANDIDATE: %ld\n", int_candidate);
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

int	is_number(char *nbr, t_ps *ps)
{
	int			i;
	int			offset;
	int			signal;
	t_nbr_info	nbr_info;

	nbr_info = get_nbr_info(nbr);
	offset = nbr_info.offset;
	i = offset;
	signal = nbr_info.signal;
	while (nbr[i])
		if (!ft_isdigit(nbr[i++]))
			return (set_error(e_input_must_be_integers, ps));
	if (!is_integer(&nbr[offset], signal))
		return (set_error(e_invalid_nbr_len, ps));
	return (true);
}

int	get_nbr_from(char *str)
{
	int			nbr;
	int			offset;
	int			signal;
	t_nbr_info	nbr_info;

	nbr_info = get_nbr_info(str);
	offset = nbr_info.offset;
	signal = nbr_info.signal;
	nbr = ft_atoi(str + offset);
	return (signal * nbr);
}

/** 
 * printf("nbr: %d\n\n", *nbrs[i]);
 * TODO: Remove error knowledge from ft_malloc_nbrs.
 *       Create a function set_null_error(error_code, ps) -> NULL
 **/
int	**get_nbrs_from(char **arr, int args, t_ps *ps)
{
	int	**nbrs;
	int	i;

	nbrs = ft_malloc_nbrs(args, ps);
	if (!nbrs || !*nbrs)
		return (NULL);
	i = -1;
	while (++i < args)
		*nbrs[i] = get_nbr_from(arr[i]);
	return (nbrs);
}
