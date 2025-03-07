NAME = so_long
BNS_NAME = bonus_

SRC = check.c count.c getNexLine/get_next_line.c getNexLine/get_next_line_utils.c flood_fill.c window.c additional.c

BNS = Bonus/check.c Bonus/count.c Bonus/getNexLine/get_next_line.c Bonus/getNexLine/get_next_line_utils.c Bonus/flood_fill.c Bonus/window.c Bonus/additional.c Bonus/additional2.c Bonus/freeing.c

FLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

OBJ = $(SRC:.c=.o)
BNS_OBJ = $(BNS:.c=.o)

libmlx = ./minilibx-linux/libmlx_Linux.a

PRINTF_DIR = ft_printf/libftprintf.a

$(NAME): $(OBJ) $(PRINTF_DIR)
	$(CC) $(OBJ) -o $(NAME) $(libmlx) -lXext -lX11 ft_printf/libftprintf.a

$(PRINTF_DIR):
	@$(MAKE) -C ft_printf

all: $(NAME) $(PRINTF_DIR)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(BNS_NAME): $(BNS_OBJ) $(PRINTF_DIR)
	$(CC) $(BNS_OBJ) -o $(BNS_NAME) $(libmlx) -lXext -lX11 ft_printf/libftprintf.a

bonus: $(BNS_NAME)


clean:
	$(RM) $(OBJ) $(BNS_OBJ)
	@$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(NAME) $(BNS_NAME)
	@$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
.SECONDARY : $(OBJ) $(BNS_OBJ)
