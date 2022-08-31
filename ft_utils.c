/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheng <jcheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:23:37 by jcheng            #+#    #+#             */
/*   Updated: 2022/08/31 22:36:39 by jcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "print.h"
#include <stdio.h>
#include <unistd.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int c = 65;
	//printf("\n%d\n", ft_putchar(c));
	//return (0);
	ft_putchar(c);
}