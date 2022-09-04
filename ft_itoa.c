/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:48:36 by jcheng            #+#    #+#             */
/*   Updated: 2022/09/04 16:58:38 by jcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_convert(long n, char *str)
{
	if (n > 9)
	{
		ft_convert (n / 10, str);
		ft_convert (n % 10, str);
	}
	else
		*str++ = n + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	long	number;

	number = n;
	result = malloc(sizeof(char) * (ft_numlen(number) + 1));
	if (!result)
		return (0);
	i = 0;
	if (number < 0)
	{
		result[i] = '-';
		number *= -1;
		i++;
	}
	ft_convert(number, result);
	result[i] = '\0';
	return (result);
}

// int	main(void)
// {
// 	int	n = 1456723;
// 	printf("output:%s", ft_itoa(n));
// }