# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 12:20:52 by mobenais          #+#    #+#              #
#    Updated: 2026/10/03 23:06:00 by tristan-gscn     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output
NAME		= libftprintf.a

# Commands
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -MMD -MP
AR		= ar -rcs
RM		= rm -rf
MKDIR		= mkdir -p

# Directories
INCDIR		= include
SRCDIR		= src
OBJDIR		= .obj
DEPDIR		= .dep

IFLAGS		= -I$(INCDIR)
CF		= $(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS)

# Sources
SRCS		= ft_printf.c \
		  utils.c \
		  utilsbis.c

# Objects and Dependencies
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS		= $(addprefix $(DEPDIR)/, $(SRCS:.c=.d))

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: all

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(DEPDIR)
	$(CF) -MF $(DEPDIR)/$*.d -c $< -o $@

$(OBJDIR) $(DEPDIR):
	$(MKDIR) $@

clean:
	$(RM) $(OBJDIR) $(DEPDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include $(DEPS)
