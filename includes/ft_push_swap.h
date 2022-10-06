/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:25:51 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/06 18:51:04 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libs/libft/include/libft.h"

# define ERROR "Error\n"
# define INTEGER "One should provide only integers as input to push_swap"
# define INTEGER_LEN "Invalid input range"
# define BAD_INPUT "Your input: \n"
# define MEMORY_ERROR "Error to allocate memory"
# define USAGE_MSG "push_swap usage: ./puss_swap n1 n2 n3 ... nn"
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define INT_MAX_LEN 10

// Enums
enum e_bool
{
	false,
	true
};

enum e_error_msg_codes
{
	e_no_error,
	e_bad_input,
	e_should_not_display_error,
	e_input_must_be_integers,
	e_invalid_nbr_len,
	e_mem_allocation,
};

// Structs
typedef struct s_ps
{
	int	fl_error;
	int	is_heap_allocated;
	int	nbr_elements;
}	t_ps;

// Data handlers
int			ft_ps_init(int argc, char **argv, t_ps *ps);

// Arg parsers

// Error handlers
void		ft_error(t_ps *ps);
int			set_error(int error_code, t_ps *ps);

// Input validators
int			input_validating(int argc, char **argv, t_ps *ps);

// Numbers

// Memory
void		ft_doublefree_size(void **arr, int to_be_freed);
int			**ft_malloc_nbrs(int args, t_ps *ps);

#endif
