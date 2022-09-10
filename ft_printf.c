/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:56:31 by jcheng            #+#    #+#             */
/*   Updated: 2022/09/10 16:52:57 by jcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_specifiers(va_list args, char specifier, int a);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += printf_specifiers(args, str[i + 1], count);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	printf_specifiers(va_list args, char specifier, int a)
{
	if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'c')
		a += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		a += ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		a += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		a += ft_putnbr_u(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		a += ft_hexa(va_arg(args, int), specifier);
	else if (specifier == 'p')
		a += ft_print_pointer(va_arg(args, unsigned long));
	return (a);
}

// int	main(void)
// {
// 	int	a = 10;
// 	int	*ptr = &a;

// 	ft_printf("hello%cworld\n", 48);
// 	ft_printf("%s\n", "dfghjk");
// 	ft_printf("%i\n", 'i');
// 	ft_printf("%u\n", -20);
// 	ft_printf("%x\n", 479);
// 	ft_printf("%X\n", 0);
// 	ft_printf("%%\n");
// 	ft_printf("%p\n", ptr);
// 	printf("%p", ptr);
// }
