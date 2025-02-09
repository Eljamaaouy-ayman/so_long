NAME = so_long
BNS_NAME = bonus

SRC = check.c count.c getNexLine/get_next_line.c getNexLine/get_next_line_utils.c

BNS = 

OBJ = $(SRC:.c=.o)
BNS_OBJ = $(BNS:.c=.o)

FLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(BNS_NAME): $(BNS_OBJ)
	$(CC) $(BNS_OBJ) -o $(BNS_NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

bonus: $(BNS_NAME)

clean:
	@$(RM) $(OBJ) $(BNS_OBJ)

fclean: clean
	@$(RM) $(NAME) $(BNS_NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY : $(OBJ) $(BNS_OBJ)