#variables
NAME	=	libftprintf.a
INCLUDE	=	ft_printf.h
GCC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
ARCCS	=	ar rcs
RM		= 	rm -rf

#mandatory
SRCS	=	ft_printf.c ft_utils.c ft_hexa.c ft_pointer.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(ARCCS) $(NAME) $(OBJS)

# %.o	:	%.c
# 	$(GCC) $(CFLAGS) -I. -c $< -o $@

test:
	@$(GCC) $(CFLAGS) $(SRCS) -o test.out && ./test.out
	@$(RM) ./test.out

norm: 
	norminette -R CheckForbiddenSourceError $(SRCS) ft_printf.h

#remove files
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: libftprintf.a