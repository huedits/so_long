NAME = so_long
MGNAME = mapgen

LIBPATH = ./libs/
SRCPATH = ./srcs/
FTPATH = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
LXFLAGS = -lX11 -lXext -lmlx

RM = rm -rf

SRCS = $(addprefix $(SRCPATH), 	so_long.c \
								so_long_utils.c \
								map_validation.c \
								map_validation_2.c \
								handlers.c \
								game.c )

MGSRCS = $(addprefix $(SRCPATH)mapgen/,	map_generator.c \
										map_generator_utils.c )

all: $(NAME)

$(NAME): $(FTPATH) $(MGNAME) $(SRCS)
	$(CC) -I $(LIBPATH) $(SRCS) $(FTPATH) -g3 -o $@ $(CFLAGS) $(LXFLAGS)

$(MGNAME):
	$(CC) $(CFLAGS) -I $(LIBPATH) $(MGSRCS) -g3 -o $@

clean:
	$(RM) *.o
	$(MAKE) clean -C ./libft/
	$(RM) leaks*.txt

fclean: clean
	$(RM) $(MGNAME)
	$(RM) $(NAME)
	$(RM) $(FTPATH)

$(FTPATH):
	$(MAKE) all -C ./libft/

val:
	valgrind --leak-check=full ./$(arg) 2> leaks_$(arg).txt

re: fclean all

regen:
	$(RM) $(MGNAME)
	$(MAKE) $(MGNAME)
	./mapgen

git: fclean
	git add .
	sleep 5
	git commit -m "Automatic commit from Makefile"
	git push

.PHONY: all clean fclean re regen git val libft