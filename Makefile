# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 11:55:29 by itkimura          #+#    #+#              #
#    Updated: 2022/09/13 23:13:46 by itkimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TARGET
NAME			= push_swap
CHECKER			= checker

# GCC
FLAGS			= -Wall -Werror -Wextra
INCL			= -I./includes/ -I./libft/includes/

# DIRECTORIES
SHARED_DIR		= ./srcs/shared/
PUSH_DIR		= ./srcs/push_swap/
CHECKER_DIR		= ./srcs/checker/
VISUAL_DIR		= ./srcs/visualizer/
OBJS_DIR		= ./objects/

# FILES
SHARED_FILES	= validation.c			init_stack.c	operations.c	\
				  apply_operations.c	is_sorted.c		print.c
PUSH_FILES		= push_swap.c			dfs.c			print_answer.c	\
				  index.c				quick_sort.c
CHECKER_FILES 	= checker.c
VISUAL_FILES 	= visualizer.c
SHARED_OBJS		= $(addprefix	$(OBJS_DIR), $(SHARED_FILES:.c=.o))
PUSH_OBJS		= $(addprefix	$(OBJS_DIR), $(PUSH_FILES:.c=.o))
CHECKER_OBJS	= $(addprefix	$(OBJS_DIR), $(CHECKER_FILES:.c=.o))
VISUAL_OBJS		= $(addprefix	$(OBJS_DIR), $(VISUAL_FILES:.c=.o))

# LIBFT
LIB				= -L./libft/ -lft
LIBFT			= /libft/libft.a

# COLORS
GREEN			:= $(shell tput -Txterm setaf 2)
YELLOW			:= $(shell tput -Txterm setaf 3)
WHITE			:= $(shell tput -Txterm setaf 7)
RESET			:= $(shell tput -Txterm sgr0)
BOLD			:= $(shell tput bold)


all: libft $(OBJS_DIR) $(NAME) $(CHECKER)

libft: $(LIBFT)

$(LIBFT):
# make -s fclean -C ./libft && make -s -C ./libft
	@make -s -C ./libft

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(PUSH_DIR)%.c
	@gcc $(FLAGS) $(INCL) -o $@ -c $<

$(OBJS_DIR)%.o: $(SHARED_DIR)%.c
	@gcc $(FLAGS) $(INCL) -o $@ -c $<

$(OBJS_DIR)%.o: $(CHECKER_DIR)%.c
	@gcc $(FLAGS) $(INCL) -o $@ -c $<

$(OBJS_DIR)%.o: $(VISUAL_DIR)%.c
	@gcc $(FLAGS) $(INCL) -o $@ -c $<

$(NAME): $(OBJS_DIR) $(SHARED_OBJS) $(PUSH_OBJS)
	@gcc $(FLAGS) $(INCL) -o $@ $(SHARED_OBJS) $(PUSH_OBJS) $(LIB)
	@echo "${BOLD}[push_swap]${RESET}\tCompiled!"

$(CHECKER): $(CHECKER_OBJS) $(SHARED_OBJS) $(VISUAL_OBJS)
	@gcc $(FLAGS) $(INCL) -o $@ $(CHECKER_OBJS) $(SHARED_OBJS) $(VISUAL_OBJS) $(LIB)
	@echo "${BOLD}[checker]${RESET}\tCompiled!"

clean:
	@rm -rf $(OBJS_DIR)
	@make -s clean -C ./libft
	@echo "${BOLD}[push_swap]${RESET}\tObject files has been deleted"
	@echo "${BOLD}[checker]${RESET}\tObject files has been deleted"

fclean:
	@make -s fclean -C ./libft
	@rm -rf $(OBJS_DIR)
	@echo "${BOLD}[push_swap]${RESET}\tObject files has been deleted"
	@rm -f $(NAME) $(CHECKER)
	@echo "${BOLD}[push_swap]${RESET}\tExcutable file has been deleted"
	@echo "${BOLD}[checker]${RESET}\tObject files has been deleted"
	@echo "${BOLD}[checker]${RESET}\tExcutable file has been deleted"

re: fclean all

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

.PHONY: all clean fclean re

