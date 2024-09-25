NAME := ./main
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp Harl.cpp

OBJS := $(SRCS:.cpp=.o)

HEADERS := Harl.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJS)
