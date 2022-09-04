/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:23:37 by jcheng            #+#    #+#             */
/*   Updated: 2022/09/04 17:05:52 by jcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += ft_putstr("(null)");
		str++;
	}
	while (!str)
	{
		i += ft_putchar(*str);
		str++;
	}
	return (i);
}

int	ft_putnbr_len(int n)
{
	int		digit_len;
	char	*number;

	number = ft_itoa(n);
	digit_len = ft_putstr(number);
	free (number);
	return (digit_len);
}

// int	ft_putnbr(int n)
// {
// 	int	a;

// 	a = 0;
// 	if (n == -2147483648)
// 	{
// 		a += ft_putchar('-');
// 		a += ft_putchar('2');
// 		n = 147483648;
// 	}
// 	if (n < 0)
// 	{
// 		a += ft_putchar('-');
// 		n *= -1;
// 	}
// 	if (n > 9)
// 	{
// 		a += ft_putnbr(n / 10);
// 		n %= 10;
// 	}
// 	else
// 		a += ft_putnbr(n + 48);
// 	return (a);
// }

// int	main(void)
// {
// //	char *str = "fghj";
// 	printf("output:%d", ft_putnbr('1234'));
// }