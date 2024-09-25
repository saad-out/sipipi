NAME := ./zombie
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
HEADERS := Zombie.hpp

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

.SECONDARY: $(OBJS)
