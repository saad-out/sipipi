NAME := ./main
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
HEADERS := Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
