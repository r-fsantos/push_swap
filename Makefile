# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 08:23:33 by rfelicio          #+#    #+#              #
#    Updated: 2022/10/03 19:12:14 by rfelicio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	clang
CC_FLAGS	=	-Wall -Wextra -Werror -g3

LEAK_FLAGS	=	-fsanitize=address

ifeq ($(shell uname), Linux)
	LEAK_FLAGS =
endif

# Libft
LIBFT_DIR		:= ./libs/libft
LIBFT_HEADERS 	:= $(LIBFT_DIR)/include
LIBFT			:= $(LIBFT_DIR)/libft.a
LIBFT_MAKE		:= make -C $(LIBFT_DIR)
LIBFT_CLEAN		:= make clean -C $(LIBFT_DIR)
LIBFT_FCLEAN	:= make fclean -C $(LIBFT_DIR)
LIBFT_RE		:= make re -C $(LIBFT_DIR)
LIBFT_FLAGS		:= -L $(LIBFT_DIR) -lft

FLAGS		=	$(CC_FLAGS) $(LEAK_FLAGS) $(LIBFT_FLAGS)

HEADERS_DIR	=	./includes
HEADERS		=	 -I $(HEADERS_DIR) -I $(LIBFT_HEADERS)

SRC_DIR		=	./src
SRC			=	$(SRC_DIR)/main.c					\
				$(SRC_DIR)/ft_error.c				\
				$(SRC_DIR)/ft_input_validating.c	\

OBJ_DIR		= ./obj
OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling..."
	$(CC) $(CC_FLAGS) $< -c -o $@ $(HEADERS)
	@echo

$(NAME): $(OBJ_DIR) $(OBJ)
	$(LIBFT_MAKE)
	@echo "Linking..."
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(HEADERS)
	@echo

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Cleaning object files..."
	@echo
	$(LIBFT_CLEAN)
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
