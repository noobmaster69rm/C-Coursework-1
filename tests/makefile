NAME=test

CC=g++ -std=c++20
FLAGS=-Wall -Werror -Wextra
SRC=tests.cpp
RM =rm -rf

.PHONY: all

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(LIBS) $(SRC) -o $(NAME)

clean:
	$(RM) $: (OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)

debug: fclean
	$(CC) $(FLAGS) $(SRC) -o $(NAME)