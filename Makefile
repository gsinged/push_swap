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

NAME_PS = push_swap
NAME_CH = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR  = ./src/
INCDIR  = ./inc/
OBJDIR  = ./obj/
FTDIR   = ./libft/

SRC = init_ps.c move.c moves.c moves_b.c moves_c.c ps.c ps_atoi.c \
	ps_step1_chunk.c ps_step2_chunk.c ps_step_1.c ps_step_2.c ps_step_3.c \
	struct_doubly_linked_list.c struct_doubly_linked_list_b.c \
	struct_doubly_linked_list_c.c struct_doubly_linked_list_d.c \
	struct_doubly_linked_list_e.c struct_doubly_linked_list_f.c \
	struct_doubly_linked_list_g.c struct_ps.c

PS_SRC = push_swap.c
PS_OBJ = $(addprefix $(OBJDIR),$(PS_SRC:.c=.o))

CH_SRC = checker.c ch.c
CH_OBJ = $(addprefix $(OBJDIR),$(CH_SRC:.c=.o))

OBJ	= $(addprefix $(OBJDIR),$(SRC:.c=.o))
LIBFT = $(FTDIR)libft.a

.PHONY: all clean fclean count

all: $(NAME_PS) $(NAME_CH)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(FTDIR)/inc/ -I $(FTDIR)/ft_printf/inc/ -o $@ -c $<

$(LIBFT):
	make -sC $(FTDIR)

$(NAME_PS): obj $(LIBFT) $(OBJ) $(PS_OBJ)
	$(CC) $(OBJ) $(PS_OBJ) $(LIBFT) -o $(NAME_PS)

$(NAME_CH): obj $(LIBFT) $(OBJ) $(CH_OBJ)
	$(CC) $(OBJ) $(CH_OBJ) $(LIBFT) -o $(NAME_CH)

count:
	wc ./src/*.c ./inc/*.h

clean:
	rm -rf $(OBJDIR)
	make -sC $(FTDIR) clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CH)
	make -sC $(FTDIR) fclean

re: fclean all

