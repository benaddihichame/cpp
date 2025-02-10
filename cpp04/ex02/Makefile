CPPCOMPILER = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = Animal
RM = rm -rf

SRC = main.cpp Cat.cpp Dog.cpp AAnimal.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
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
