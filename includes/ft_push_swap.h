/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:25:51 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/03 10:05:53 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define ERROR "Error\n"
# define INTEGER "One should provide only integers as input to push_swap"
# define BAD_INPUT "Your input: \n"
# define MEMORY_ERROR "Error to allocate memory"
# define USAGE_MSG "push_swap usage: ./puss_swap n1 n2 n3 ... nn"

// Enums
enum e_bool
{
	false,
	true
};

enum e_error_msg_codes
{
	e_should_not_display_error,
	e_no_error,
	e_bad_input,
};

// Structs
typedef struct s_ps
{
	int	fl_error;
}	t_ps;

// Error handlers
void	ft_error(t_ps *ps);

// Input validators
int		input_validating(int argc, char **argv, t_ps *ps);

#endif
