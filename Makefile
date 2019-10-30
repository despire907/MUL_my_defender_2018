##
## EPITECH PROJECT, 2019
## MUL_my_defender_2018
## File description:
## makefile
##

CC	= gcc -g

RM	= rm -f

NAME = my_defender

SRC	= main.c    \
      menu_function.c   \
      my_defender.c \
      init.c    \
      gui.c     \
      button_position.c \
      turret_function.c \
      event.c   \
      linked_list.c   \
      rec.c \
      init_struct.c \
      placer_turret.c   \
      aim.c \
      struct_bis.c  \
      temp.c    \
      detect_hit.c  \
      mob_life.c    \
      game_over.c   \
      gold.c    \
      win.c \
      free_all.c    \
      free_struct.c \
      frre_struct_bis.c \
      color.c   \
      pause.c   \
      mouse.c   \
      init_sprite.c \
      sound.c   \
      how_to_play.c \
      add_more_fonction.c   \
      scorboard.c   \
      get_next_line.c   \
      my_str_c_dup.c    \
      display_score.c

OBJ	= $(addprefix src/,$(SRC:.c=.o))

CFLAGS	= -lcsfml-graphics -lcsfml-window -lcsfml-system -l csfml-audio -W -Wextra -Wall -I include/

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
