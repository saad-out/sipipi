NAME := ./main
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
HEADERS := AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

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
