#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf("%c\n", 'h');
	printf("Hello %s\n", "world!");
	ft_printf("Hello %s\n", "world!");
}