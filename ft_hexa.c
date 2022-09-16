/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:33:30 by jcheng            #+#    #+#             */
/*   Updated: 2022/09/16 14:49:21 by jcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_hexa(unsigned int n, char specifier)
{
	int	a;

	a = 0;
	if (n >= 16)
	{
		a += ft_hexa((n / 16), specifier);
		a += ft_hexa((n % 16), specifier);
	}
	else
	{
		if (n <= 9)
			a += ft_putchar(n + 48);
		else
		{
			if (specifier == 'x')
				a += ft_putchar(n - 10 + 'a');
			if (specifier == 'X')
				a += ft_putchar(n - 10 + 'A');
		}
	}
	return (a);
}

// int	main(void)
// {
// 	int	n = 257;

// 	printf("%x", n);
// }