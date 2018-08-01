# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcasian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 15:26:05 by jcasian           #+#    #+#              #
#    Updated: 2018/08/01 15:43:52 by jcasian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCSDIR = srcs
LIBSDIR = libs
SRCS = $(addprefix $(SRCSDIR)/,\
	   ft_printf.c struct_handle.c checks.c print_var.c is_tests.c \
	   put_error.c check_lengthspt2.c)

INCLUDES = 	includes
OBJECTS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

%.o: %.c
	gcc -c -Wall -Werror -Wextra -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS)
	ar rc libs/$(NAME) $(OBJECTS)
	ranlib libs/$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f libs/$(NAME)

re: fclean all

test: re clean
	gcc -Wall -Werror -Wextra srcs/main.c -I$(INCLUDES) -L$(LIBSDIR) -lft -lftprintf -o test

testclean: fclean
	rm -rf test

retest: testclean test clean

debug:
	gcc -g -Wall -Wextra -Werror -I$(INCLUDES) srcs/*.c libft/*.c -o debug

debugclean:
	rm -rf debug*

redebug: debugclean debug
