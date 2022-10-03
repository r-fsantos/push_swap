/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:25:51 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/03 08:19:34 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>

# define BAD_INPUT "Bad input: \n"
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
	e_no_error = 0,
	e_bad_input = 1,
};

#endif
