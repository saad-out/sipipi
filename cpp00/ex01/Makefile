NAME := ./contact
CC := g++
CFLAGS := -Wall -Wextra -Werror

SRCS := Contact.cpp PhoneBook.cpp main.cpp
HEADERS := Contact.hpp PhoneBook.hpp

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
