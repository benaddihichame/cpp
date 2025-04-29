CPPCOMPILER = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = RPN
RM = rm -rf

SRC = main.cpp BitcoinExchange.cpp
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
