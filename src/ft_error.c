/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:56:36 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/03 23:03:51 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_error(t_ps *ps)
{
	if (ps->fl_error == e_should_not_display_error)
		exit(0);
	if (ps->fl_error == e_input_must_be_integers)
		ft_putendl_fd(ERROR INTEGER, 2);
	exit(0);
}

int	set_error(int error_code, t_ps *ps)
{
	ps->fl_error = error_code;
	return (false);
}
