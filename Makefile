# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcasian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/04 18:30:42 by jcasian           #+#    #+#              #
#    Updated: 2018/08/06 20:57:40 by jcasian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBSDIR = libs

SRCSDIR = srcs

LIBFTDIR = libft

INCLUDES = includes

SRCS = $(addprefix $(SRCSDIR)/,\
	   ft_printf.c print_error.c struct_handle.c checks_after_percentage.c \
	   is_tests.c prepare_str.c prepare_percentage.c prepare_address.c \
	   prepare_hexadecimal.c prepare_undecimal.c prepare_octal.c \
	   prepare_binary.c prepare_signed.c prepare_char.c)

LIBFTSRCS = $(addprefix $(LIBFTDIR)/,\
			ft_putchar.c ft_putendl.c ft_putstr.c ft_atoi.c ft_strdup.c \
			ft_strlen.c ft_wstrdup.c ft_wchar_len.c ft_wstrlen.c \
			ft_straddprefix.c ft_straddsuffix.c ft_wstraddprefix.c \
			ft_wstraddsuffix.c ft_strnew.c ft_wstrnew.c ft_putwchar.c \
			ft_utoabaselonglong.c ft_strtoupper.c ft_toupper.c \
			ft_itoalonglong.c)

OBJECTS = $(patsubst %.c, %.o, $(SRCS))

LIBFTOBJECTS = $(patsubst %.c, %.o, $(LIBFTSRCS))

all: $(NAME)

%.o: %.c
	@gcc -c -Wall -Werror -Wextra -I$(INCLUDES) -c $< -o $@

printmsg:
	@echo "Preparing library... Please wait"

$(NAME): printmsg $(OBJECTS) $(LIBFTOBJECTS)
	@ar rc $(LIBSDIR)/$(NAME) $(OBJECTS) $(LIBFTOBJECTS)
	@ranlib $(LIBSDIR)/$(NAME)
	@echo "Library is ready!"

clean:
	@echo "Cleanning objects..."
	@rm -f $(OBJECTS) $(LIBFTOBJECTS)

fclean: clean
	@echo "Deleting library..."
	@rm -f $(LIBSDIR)/$(NAME)

re: fclean all

test: re
	@echo "Creating test..."
	@gcc srcs/test.c -L$(LIBSDIR) -lftprintf -I$(INCLUDES) -o test
	@echo "Test Succesfully created!"

testclean: fclean
	@echo "Deleting test..."
	@rm test

retest: testclean test

debugclean:
	@rm -rf debug*

debug: debugclean
	@gcc -g srcs/test.c $(SRCS) $(LIBFTSRCS) -I$(INCLUDES) -o debug
