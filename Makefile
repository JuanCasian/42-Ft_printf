# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcasian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 15:26:05 by jcasian           #+#    #+#              #
#    Updated: 2018/08/03 19:50:00 by jcasian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCSDIR = srcs

LIBFTDIR = libft

LIBFTSRCS = $(addprefix $(LIBFTDIR)/,\
	ft_atoi.c ft_bzero.c ft_count_words.c ft_filetostr.c ft_is_space.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
	ft_memmove.c ft_memset.c ft_printlist.c ft_putchar.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	ft_putstr_fd.c ft_remalloc.c ft_samplelist.c ft_strcat.c ft_strchr.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_strinit.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c \
	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	get_next_line.c)

SRCS = $(addprefix $(SRCSDIR)/,\
	address_tostr.c apply_flags.c apply_preci.c apply_width.c char_tostr.c \
	checks.c checkspt2.c ft_itoalong.c ft_printf.c ft_strtoupper.c ft_utoabase.c \
	get_andprint.c handle_groups.c is_tests.c put_error.c str_manipulation.c \
	struct_handle.c wchar_functions.c wchar_functionspt2.c wstr_manipulation.c)

INCLUDES = includes

LIBFTOBJECTS = $(patsubst %.c, %.o, $(LIBFTSRCS))

OBJECTS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

%.o: %.c
	gcc -c -Wall -Werror -Wextra -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFTOBJECTS)
	ar rc $(NAME) $(OBJECTS) $(LIBFTOBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS) $(LIBFTOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	gcc main.c -L. -lftprintf -I$(INCLUDES) -o test

testclean: fclean
	rm test
