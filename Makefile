# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 12:20:52 by mobenais          #+#    #+#              #
#    Updated: 2025/11/20 15:56:05 by mobenais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = srcs
INCDIR = include

SRC = ft_printf.c\
	  utils.c\
	  utilsbis.c

OBJ = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(SRCDIR)/%.o:$(SRCDIR)/%.c
	cc -Wall -Wextra -Werror -Iinclude -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
