NAME := ./main
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

SRCS := ClapTrap.cpp main.cpp FragTrap.cpp DiamondTrap.cpp ScavTrap.cpp
HEADERS := ClapTrap.hpp FragTrap.hpp DiamondTrap.hpp ScavTrap.hpp

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

.SECONDARY : $(OBJS)
