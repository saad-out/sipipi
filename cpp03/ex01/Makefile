NAME := ./main
CC := c++
CFLAGS := -Wall -Wextra -Werror

SRCS := ClapTrap.cpp main.cpp ScavTrap.cpp
HEADERS := ClapTrap.hpp ScavTrap.hpp

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
