NAME = so_long
LIBPATH = ./libs/
SRCPATH = ./srcs/
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = $(addprefix $(SRCPATH),	map_generator.c \
								map_generator_utils.c )
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(LIBPATH) $(SRCS) main.c -g3 -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

run:
	valgrind ./$(NAME) 2> leaks.txt

git: fclean
	git add .
	sleep 5
	git commit -m "Automatic commit from Makefile"
	git push