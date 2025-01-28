CPPCOMPILER = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = ClapTrap
RM = rm -rf

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPPCOMPILER) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPPCOMPILER) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(NAME)

fclean :
	$(RM) $(OBJ) $(NAME)

re : fclean all
