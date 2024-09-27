NAME := ./main
CXX := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := Fixed.cpp main.cpp Point.cpp bsp.cpp
HEADERS := Fixed.hpp Point.hpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJS)
