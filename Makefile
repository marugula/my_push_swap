NAME = push_swap

NAME_BONUS = my_checker

HEADER = push_swap.h

LIB = libft/libft.a

SRSC =	ps.c ps_utils.c		ps_atoi_mod.c		ps_push.c			ps_swap_rotate.c \
		ps_cmds1.c			ps_cmds2.c			ps_filling_lst.c	ps_sort_to3_to6.c\
		ps_find_mid.c		ps_find_pozition.c	ps_rating.c			ps_rating_min_of_max.c\
		ps_rating_more.c

SRSC_B = bonus_cheker.c		ps_filling_lst.c	ps_utils.c		ps_swap_rotate.c	ps_push.c\
							ps_atoi_mod.c		bonus_exec_Instruct.c

OBJ = $(SRSC:%.c=%.o)

OBJ_B = $(SRSC_B:%.c=%.o)

CC = cc

FLAGS = -g -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re bonus_re

all: libre $(NAME)

bonus: libre $(NAME_BONUS)

$(NAME_BONUS):  $(LIB) $(OBJ_B) $(HEADER)
	$(CC) $(OBJ_B) $(FLAGS) -Llibft -lft -o $(NAME_BONUS)




libre:
	@cd libft && make

$(NAME):  $(LIB) $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(FLAGS) -Llibft -lft -o $(NAME)

%.o : %.c  $(HEADER)
	$(CC) $(FLAGS) -Ilibft -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_B)

libclean:
	@cd libft && make clean

fclean: clean libclean
	rm -rf $(NAME) $(NAME_BONUS)

bonus_re: fclean bonus

re: fclean all