NAME := ./btc
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp BitCoinExchange.cpp
HEADERS := BitCoinExchange.hpp

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
