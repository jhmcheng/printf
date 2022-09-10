/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:23:37 by jcheng            #+#    #+#             */
/*   Updated: 2022/09/10 16:53:03 by jcheng           ###   ########.fr       */
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
	while (str[i])
	{
		i += ft_putchar(str[i]);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	a;

	a = 0;
	if (n == -2147483648)
	{
		a += ft_putchar('-');
		a += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		a += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		a += ft_putnbr(n / 10);
		a += ft_putnbr(n % 10);
	}
	else
		a += ft_putchar(n + 48);
	return (a);
}

int	ft_putnbr_u(unsigned int n)
{
	int	a;

	a = 0;
	if (n > 9)
	{
		a += ft_putnbr(n / 10);
		a += ft_putnbr(n % 10);
	}
	else
		a += ft_putchar(n + 48);
	return (a);
}

// int	main(void)
// {
// 	ft_putnbr_u(-20);
// 	// printf("output:%d\n", ft_putnbr(534567));
	
// 	// char *str = NULL;
// 	// printf("output:%s", str);
// }