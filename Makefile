# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 12:20:52 by mobenais          #+#    #+#              #
#    Updated: 2026/10/03 23:04:00 by tristan-gscn     ###   ########.fr        #
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
MANDATORY_DIR	= $(SRCDIR)/mandatory
OBJDIR		= .obj
DEPDIR		= .dep

IFLAGS		= -I$(INCDIR)
CF		= $(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS)

# Sources
MANDATORY_SRCS	= ft_printf.c \
		  utils.c \
		  utilsbis.c

# Objects and Dependencies
MANDATORY_OBJS	= $(addprefix $(OBJDIR)/mandatory/, $(MANDATORY_SRCS:.c=.o))
MANDATORY_DEPS	= $(addprefix $(DEPDIR)/mandatory/, $(MANDATORY_SRCS:.c=.d))

# Rules
all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	$(AR) $@ $^

bonus: all

$(OBJDIR)/mandatory/%.o: $(MANDATORY_DIR)/%.c | $(OBJDIR)/mandatory $(DEPDIR)/mandatory
	$(CF) -MF $(DEPDIR)/mandatory/$*.d -c $< -o $@

$(OBJDIR)/mandatory $(DEPDIR)/mandatory:
	$(MKDIR) $@

clean:
	$(RM) $(OBJDIR) $(DEPDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include $(MANDATORY_DEPS)
