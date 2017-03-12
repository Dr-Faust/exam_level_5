NAME = infin_mult
CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = infin_mult_norm.o

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
