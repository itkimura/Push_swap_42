# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 11:55:29 by itkimura          #+#    #+#              #
#    Updated: 2022/08/15 15:22:42 by itkimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

FLAGS = -Wall -Werror -Wextra

SRCS_DIR = ./srcs/
SRC_FILES = hello_world.c
CHECKER_FILES = checker.c
SRCS		= $(addprefix	$(SRCS_DIR), $(SRC_FILES))
OBJS		= $(addprefix	$(OBJS_DIR), $(SRC_FILES:.c=.o))
CHECKER_OBJS		= $(addprefix	$(OBJS_DIR), $(CHECKER_FILES:.c=.o))
OBJS_DIR = ./objects/
INCL = -I ./includes/ -I./libft/includes/
LIBFT = -L./libft/ -lft

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	make -s fclean -C ./libft && make -s -C ./libft
	mkdir -p $(OBJS_DIR)
	gcc $(FLAGS) $(INCL) -o $@ -c $<

$(NAME): $(OBJS)
	gcc $(FLAGS) $(INCL) -o $@ $^ $(LIBFT)

$(CHECKER_FILES):
	gcc $(FLAGS) $(INCL) -o $@ -c $<

$(CHECKER): $(CHECKER_OBJS) 
	gcc $(FLAGS) $(INCL) -o $@ $^ $(LIBFT)


clean:
	@rm -rf $(OBJS_DIR)
	@make -s clean -C ./libft

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@make -s fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re

