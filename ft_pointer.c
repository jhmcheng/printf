/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:19:27 by jcheng            #+#    #+#             */
/*   Updated: 2022/09/16 14:51:28 by jcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_pointer(uintptr_t n)
{
	int	a;

	a = 0;
	if (n >= 16)
	{
		a += ft_pointer(n / 16);
		a += ft_pointer(n % 16);
	}
	else
	{
		if (n <= 9)
			a += ft_putchar(n + 48);
		else
			a += ft_putchar(n - 10 + 'a');
	}
	return (a);
}

int	ft_print_pointer(unsigned long long num)
{
	int	i;

	i = 0;
	i += write (1, "0x", 2);
	i += ft_pointer(num);
	return (i);
}
