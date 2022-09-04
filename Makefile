#mandatory
SRCS	=	ft_printf.c ft_utils.c

OBJS	=	$(SRCS:.c=.o)

#header
INCLUDE	=	ft_printf.h

#library
ARCCS	=	ar rcs
RM		= 	rm -rf

#compiler
GCC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	ft_printf.a

all		:	$(NAME)

#mandatory
$(NAME)	:	$(OBJS)
			$(ARRCS) $(NAME) $(OBJS)

%.o	:	%.c
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all