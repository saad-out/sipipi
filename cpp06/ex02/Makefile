NAME := ./main
CXX := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp cast.cpp
HEADERS := Base.hpp A.hpp B.hpp C.hpp cast.hpp

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
