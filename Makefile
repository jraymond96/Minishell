# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/25 15:36:00 by jraymond          #+#    #+#              #
#    Updated: 2018/06/29 19:30:54 by jraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   del.c \
	   check_pars_entry.c \
	   pars_path.c \
	   handle_path.c \
	   path_permi.c \
	   pars_order.c \
	   is_builtin.c \
	   len.c \
	   if_valid_order.c \
	   cpy_envp.c \
	   call_order.c \
	   call_builtin.c \
	   echo_builtin.c \
	   unsetenv_builtin.c \
	   setenv_builtin.c \
	   error_setenv.c \
	   split_path.c \
	   cd_handle_path.c \
	   cd_builtin.c \
	   first_char_cd.c \
	   error_cd.c \
	   creat_pars_path.c \
	   env_builtin.c \
	   iter_env.c \
	   handle_envp_env.c \
	   split_line.c \
	   exec_bin.c

#COLORS

_GREEN=\x1b[32m
_RED=\x1b[31m
_YELLOW=\x1b[33m
_END=\x1b[0m

OBJS = $(SRCS:.c=.o)

all : libft printf $(NAME)

.PHONY : all fclean clean re libft printf

libft:
	@make -C libft

printf:
	@make -C ft_printf

$(NAME) : $(OBJS) ./ft_printf/libftprintf.a ./libft/libft.a
	@$(CC) $(FLAGS) ./libft/libft.a ./ft_printf/libftprintf.a $(OBJS) -o $(NAME)
	@echo "$(_GREEN)$(NAME) created$(_END)"

ce : libft ft_printf $(NAME)
	@echo "$(_YELLOW)$(NAME) result ...$(_END)"
	@./minishell

%.o : %.c
		@$(CC) $(FLAGS) -o $@ -c $^

clean :
		@make clean -C libft
		@make clean -C ft_printf
		@rm -rf $(OBJS)
		@echo "$(_RED)clean : $(_GREEN)Done$(_END)"

fclean : clean
		@make fclean -C libft
		@make fclean -C ft_printf
		@rm -rf $(NAME)
		@echo "$(_RED)fclean : $(_GREEN)Done$(_END)"

re :
	@make fclean
	@make
