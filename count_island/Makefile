NAME = count_island
CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = count_island_norm.o

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGC) $(OBJECTS) -o $(NAME)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
