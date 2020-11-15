# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 21:53:59 by gsinged           #+#    #+#              #
#    Updated: 2020/11/09 21:54:00 by gsinged          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR  = ./src/
INCDIR  = ./inc/
OBJDIR  = ./obj/
FTDIR   = ./libft/

SRC = init_ps.c moves.c moves_b.c moves_c.c ps.c ps_step_1.c ps_step_2.c \
      push_swap.c struct_doubly_linked_list.c struct_ps.c test.c

OBJ	= $(addprefix $(OBJDIR),$(SRC:.c=.o))
LIBFT = $(FTDIR)libft.a

.PHONY: all clean fclean count

all: $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(FTDIR)/inc/ -I $(FTDIR)/ft_printf/inc/ -o $@ -c $<

$(LIBFT):
	make -C $(FTDIR)

$(NAME): obj $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

count:
	wc ./src/*.c ./inc/*.h

clean:
	rm -rf $(OBJDIR)
	make -sC $(FTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -sC $(FTDIR) fclean

re: fclean all

