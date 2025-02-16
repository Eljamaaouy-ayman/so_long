CC = cc
files = ft_printf.c \
		ft_helpfuncs.c \
		ft_sec_help.c

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

OBJECT = $(files:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all re clean fclean

.SECONDARY:	$(OBJECT)
