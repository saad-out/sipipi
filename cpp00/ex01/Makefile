NAME := ./contact
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := Contact.cpp PhoneBook.cpp main.cpp
HEADERS := Contact.hpp PhoneBook.hpp Colors.hpp

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
