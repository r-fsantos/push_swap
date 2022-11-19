/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:25:51 by rfelicio          #+#    #+#             */
/*   Updated: 2022/11/19 18:09:15 by rfelicio         ###   ########.fr       */
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
# define REPEATED_NBRS "Duplicate entries are not allowed"
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
	e_should_not_display_error,
	e_input_must_be_integers,
	e_invalid_nbr_len,
	e_mem_allocation,
	e_has_repeated_nbrs,
};

// Structs
typedef struct s_stack
{
	int				ssize;
	int				nbr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ps
{
	int		fl_error;
	int		stacks_are_heap_allocated;
	int		nbrs_len;
	int		*nbrs_non_normalized;
	int		*nbrs;
	t_stack	**stack_a;
	t_stack	**stack_b;
}	t_ps;

typedef struct s_nbr_info
{
	int	offset;
	int	signal;
}	t_nbr_info;

// Data handlers
int			ft_ps_init(int argc, char **argv, t_ps *ps);
int			nbrs_normalization(t_ps *ps);

// Arg parsers
int			has_repeated_elements(int *nbrs, int len);

// Error handlers
void		ft_error(t_ps *ps);
int			set_error(int error_code, t_ps *ps);

// Input validators
int			input_validation(int argc, char **argv, t_ps *ps);

// Numbers
int			is_number(char *nbr, t_ps *ps);
t_nbr_info	get_nbr_info(char *nbr);
int			get_nbr_from(char *str);
int			*get_nbrs_from(char **arr, int args, t_ps *ps);

// Memory
void		ft_free(void *arr);
void		ft_doublefree_size(void **arr, int to_be_freed);

// Stack
int			stacks_allocation(t_ps *ps);
t_stack		*ft_new_node(int nbr, int ssize);
t_stack		*get_last_node(t_stack *stack);
void		ft_stack_add_back(t_stack **stack, t_stack *new);
void		ft_fill_stack(t_stack **stack, int *nbrs, int len);

#endif
