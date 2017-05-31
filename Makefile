# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 16:39:43 by mwooden           #+#    #+#              #
#    Updated: 2017/05/30 21:53:50 by mwooden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =\
		srcs/ft_printf.c\
		srcs/parse.c\
		srcs/init_handlers.c\
		srcs/helpers.c\
		srcs/handlers_1.c\
		srcs/wstr_handler.c\
		srcs/int_handler.c\
		srcs/handlers_2.c\
		srcs/handlers_3.c\
		srcs/unsigned_handlers.c\
		libft/ft_strchr.c\
		libft/ft_putstr.c\
		libft/ft_strlen.c\
		libft/ft_bzero.c\
		libft/my_putnstr.c\
		libft/ft_isdigit.c\
		libft/ft_memalloc.c\
		libft/ft_putchar.c\
		libft/my_greater.c\
		libft/my_putwchar.c\
		libft/ft_tolower.c\
		libft/my_putnwstr.c\
		libft/my_lesser.c\
		libft/my_putnbr_base.c\
		libft/my_putnbr_base_fd.c\
		libft/my_putwchar_fd.c\
		libft/my_putnstr_fd.c\
		libft/ft_putchar_fd.c

OBJS = $(SRCS:.c=.o)

TARGET = libftprintf.a

INCLUDES = -I inc/ft_printf_build.h

CC = gcc
AR = ar

CFLAGS ?= -Wall -Wextra -Werror
CFLAGS += $(INCLUDES)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rc $@ $^
	ranlib $@

./%.o: ./%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean $(TARGET)
