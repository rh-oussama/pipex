NAME = libfpg.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

SRCS = ft_printf.c ft_printf_utils_2.c ft_printf_utils.c \
		 ft_strncmp.c ft_split.c ft_strcmp.c \
		 get_next_line_utils.c get_next_line.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $?

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re