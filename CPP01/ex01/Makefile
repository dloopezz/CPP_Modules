NAME = zombie_horde

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC =	main.cpp\
		Zombie.cpp\
		randomChump.cpp\
		newZombie.cpp\
		zombieHorde.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean