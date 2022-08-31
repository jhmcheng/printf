/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:56:31 by jcheng            #+#    #+#             */
/*   Updated: 2022/08/31 22:08:51 by jcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	count;
	
}

int printf_specifiers(va_list args, char specifier, int a)
{
	if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'c')
		a += ft_putchar(va_arg(args, int));
}