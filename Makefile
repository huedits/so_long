NAME = so_long
MGNAME = mapgen
MVNAME = mapviz

LIBPATH = ./libs/
SRCPATH = ./srcs/

CC = cc
CFLAGS = -Wall -Wextra -Werror
LXFLAGS = -lX11 -lXext -lmlx

RM = rm -rf

MGSRCS = $(addprefix $(SRCPATH)mapgen/,	main.c \
										map_generator.c \
										map_generator_utils.c )

MVSRCS = $(addprefix $(SRCPATH)mapviz/,	map_visualizer.c \
										handlers.c )

all: $(NAME)

$(NAME): $(MGNAME)
	$(CC) $(CFLAGS) -I $(LIBPATH) $(SRCS) -g3 -o $@

$(MGNAME):
	$(CC) $(CFLAGS) -I $(LIBPATH) $(MGSRCS) -g3 -o $@

$(MVNAME):
	$(CC) $(CFLAGS) -I $(LIBPATH) $(MVSRCS) $(LXFLAGS) -g3 -o $@

del: $(arg)
	$(RM) $(arg)

clean:
	$(RM) *.o
	$(RM) leaks*.txt

fclean: clean
	$(RM) $(MGNAME)
	$(RM) $(MVNAME)
	$(RM) $(NAME)

val:
	valgrind ./$(arg) 2> leaks_$(arg).txt

re: fclean all

git: fclean
	git add .
	sleep 5
	git commit -m "Automatic commit from Makefile"
	git push