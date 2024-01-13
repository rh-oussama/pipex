# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 14:08:13 by orhaddao          #+#    #+#              #
#    Updated: 2024/01/13 15:45:07 by orhaddao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

NAME = pipex
NAME_B = pipex_bonus
LIB_src = libft_printf_gnl/ft_printf.c libft_printf_gnl/ft_printf_utils_2.c libft_printf_gnl/ft_printf_utils.c \
		 libft_printf_gnl/ft_strncmp.c libft_printf_gnl/ft_split.c \
		 libft_printf_gnl/get_next_line_utils.c libft_printf_gnl/get_next_line.c libft_printf_gnl/ft_strcmp.c
LIB_FT = libft_printf_gnl/libfpg.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -g3
FILES = src/pipex.c src/pipex_outils.c
FILES_BONUS = src/pipex_bonus.c src/pipex_outils.c src/pipex_bonus_outils.c

all: $(LIB_FT) $(NAME)

bonus: $(LIB_FT) $(NAME_B)

$(NAME_B): $(FILES_BONUS) libft_printf_gnl
	@$(CC) $(CFLAGS) $(FILES_BONUS) $(LIB_FT) -o $(NAME_B)
	@echo -e "$(GREEN)[+] pipex_bonus is ready!$(NC)"

$(NAME): $(FILES) libft_printf_gnl
	@$(CC) $(CFLAGS) $(FILES) $(LIB_FT) -o $(NAME)
	@echo -e "$(GREEN)[+] pipex is ready!$(NC)"
    
$(LIB_FT): $(LIB_src)
	@$(MAKE) -s -C libft_printf_gnl
	@echo -e "$(GREEN)[+] Compiling libft_printf_gnl...$(NC)"

clean:
	@echo -e "$(RED)[-] Removing libft_printf_gnl...$(NC)"
	@$(MAKE) -s -C libft_printf_gnl fclean

fclean: clean
	@$(MAKE) -s -C libft_printf_gnl fclean
	@rm -rf $(NAME)
	@rm -rf $(NAME_B)
	@echo -e "$(RED)[-] Removing pipex...$(NC)"

re: fclean all