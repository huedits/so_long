NAME = so_long
MGNAME = mapgen

LIBPATH = ./libs/
SRCPATH = ./srcs/

CC = cc
CFLAGS = -Wall -Wextra -Werror
LXFLAGS = -lX11 -lXext -lmlx

RM = rm -rf

SRCS = $(addprefix $(SRCPATH), so_long.c)

MGSRCS = $(addprefix $(SRCPATH)mapgen/,	map_generator.c \
										map_generator_utils.c )

all: $(NAME)

$(NAME): libft $(MGNAME)
	$(CC) $(CFLAGS) -I $(LIBPATH) $(SRCS) libft.a -g3 -o $@

$(MGNAME):
	$(CC) $(CFLAGS) -I $(LIBPATH) $(MGSRCS) -g3 -o $@
	./mapgen


clean:
	$(RM) *.o
	$(RM) leaks*.txt

fclean: clean
	$(RM) $(MGNAME)
	$(RM) $(MVNAME)
	$(RM) $(NAME)

libft:
	cd srcs/libft/ && $(MAKE) && $(MAKE) clean
	mv srcs/libft/libft.a .

val:
	valgrind ./$(arg) 2> leaks_$(arg).txt

re: fclean all

regen:
	$(RM) $(MGNAME)
	$(MAKE) $(MGNAME)

git: fclean
	git add .
	sleep 5
	git commit -m "Automatic commit from Makefile"
	git push