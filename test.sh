# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 19:59:35 by rfelicio          #+#    #+#              #
#    Updated: 2022/10/04 20:11:37 by rfelicio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

make re

echo "## Testing bad inputs"

############################################
echo "1 - Shouldn't diplay anything"

echo "1.1"
./push_swap
echo 

echo "1.2"
./push_swap
echo 

############################################
echo "2 - Not a number"
./push_swap -1 a
echo
./push_swap -1 2 3 4 5 +++++++12345678 a
