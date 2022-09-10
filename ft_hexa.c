/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:33:30 by jcheng            #+#    #+#             */
/*   Updated: 2022/09/10 15:19:12 by jcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_hexa(unsigned int n, char format)
{
	int	a;

	a = 0;
	if (n >= 16)
	{
		a += ft_hexa((n / 16), format);
		a += ft_hexa((n % 16), format);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + 48);
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			if (format == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
	return (a);
}
