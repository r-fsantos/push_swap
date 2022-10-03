# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 08:23:33 by rfelicio          #+#    #+#              #
#    Updated: 2022/10/03 08:35:58 by rfelicio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= clang
CC_FLAGS	= -Wall -Wextra -Werror -g3

LEAK_FLAGS	= -fsanitize=address

ifeq ($(shell uname), Linux)
	LEAK_FLAGS =
endif

FLAGS		= $(CC_FLAGS) $(LEAK_FLAGS)

HEADERS_DIR	= ./includes
HEADERS		= -I $(HEADERS_DIR)

SRC_DIR		= ./src
SRC			= $(SRC_DIR)/main.c

OBJ_DIR		= ./obj
OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling..."
	$(CC) $(CC_FLAGS) $< -c -o $@ $(HEADERS)
	@echo

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Linking..."
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(HEADERS)
	@echo

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Cleaning object files..."
	@echo
	@rm -rf $(OBJS_DIR)
	@echo "Finished cleaning object files"
	@echo

fclean: clean
	@echo "Cleaning executable file: $(NAME)"
	@rm -rf $(NAME)
	@echo

re: fclean all

.PHONY: all clean fclean re bonus
