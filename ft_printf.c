/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:56:31 by jcheng            #+#    #+#             */
/*   Updated: 2022/09/04 16:26:42 by jcheng           ###   ########.fr       */
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
		{
			count += printf_specifiers(args, str[i], count);
			i++;
		}
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
		a += ft_putstr(va_arg(args,char *));
	else if (specifier == 'd' || specifier == 'i')
		a += ft_putnbr_len(va_arg(args, int));
	return (a);
}

int	main(void)
{
	ft_printf("output:%c\n", ft_putchar('c'));
	ft_printf("output:%d", ft_putstr("dfghjk"));
}
