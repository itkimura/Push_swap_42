# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 11:55:29 by itkimura          #+#    #+#              #
#    Updated: 2022/08/18 17:10:02 by itkimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TARGET
NAME = push_swap
CHECKER = checker

# GCC
FLAGS = -Wall -Werror -Wextra
INCL = -I ./includes/ -I./libft/includes/

# DIRECTORIES
SRCS_DIR = ./srcs/
OBJS_DIR = ./objects/

# FILES
SRC_FILES =		push_swap.c		validate_args.c		init_stack.c \
				init_numbers.c	
CHECKER_FILES = checker.c
SRCS		= $(addprefix	$(SRCS_DIR), $(SRC_FILES))
OBJS		= $(addprefix	$(OBJS_DIR), $(SRC_FILES:.c=.o))
CHECKER_OBJS		= $(addprefix	$(OBJS_DIR), $(CHECKER_FILES:.c=.o))

# LIBFT
LIB = -L./libft/ -lft
LIBFT = /libft/libft.a

# COLORS
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
WHITE  := $(shell tput -Txterm setaf 7)
RESET  := $(shell tput -Txterm sgr0)
BOLD := $(shell tput bold)


all: libft $(OBJS_DIR) $(NAME) $(CHECKER)

help:
	@echo "Usage: ${GREEN}make${RESET} ${BOLD}command${RESET} [options]\n"
	@echo "Commands:\n"
	@echo "  ${BOLD}make${RESET}\t\t\tcompile library, push_swap and checker"
	@echo "  ${BOLD}make libft${RESET}\t\tcompile ./libft/libft.a"
	@echo "  ${BOLD}make push_swap${RESET}\tcompile push_swap"
	@echo "  ${BOLD}make checker${RESET}\t\tcompile checker"
	@echo "  ${BOLD}make clean${RESET}\t\tdelete object files"
	@echo "  ${BOLD}make fclean${RESET}\t\tdelete object files and all excutable files(libft, push_swap and checker)"
	@echo "  ${BOLD}make re${RESET}\t\tdelete object files and all excutable files and compile all again"
	@echo "  ${BOLD}help${RESET}\t\t\tprint this help message\n"

libft: $(LIBFT)

$(LIBFT):
# make -s fclean -C ./libft && make -s -C ./libft
	@make -s -C ./libft

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@gcc $(FLAGS) $(INCL) -o $@ -c $<

$(NAME): $(OBJS_DIR) $(OBJS)
	@gcc $(FLAGS) $(INCL) -o $@ $(OBJS) $(LIB)
	@echo "${BOLD}[push_swap]${RESET}\tCompiled!"

$(CHECKER): $(OBJS_DIR) $(CHECKER_OBJS) 
	@gcc $(FLAGS) $(INCL) -o $@ $(CHECKER_OBJS) $(LIB)
	@echo "${BOLD}[checker]${RESET}\tCompiled!"

clean:
	@rm -rf $(OBJS_DIR)
	@make -s clean -C ./libft
	@echo "${BOLD}[push_swap]${RESET}\tObject files has been deleted"

fclean:
	@make -s fclean -C ./libft
	@rm -rf $(OBJS_DIR)
	@echo "${BOLD}[push_swap]${RESET}\tObject files has been deleted"
	@rm -f $(NAME) $(CHECKER)
	@echo "${BOLD}[push_swap]${RESET}\tExcutable file has been deleted"

re: fclean all

.PHONY: all clean fclean re

