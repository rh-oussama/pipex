/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:09:21 by orhaddao          #+#    #+#             */
/*   Updated: 2023/11/26 13:10:11 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		else
		{
			count += ft_putchar('-');
			nb = -nb;
		}
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else if (nb >= 0 && nb <= 9)
		count += ft_putchar(nb + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_putnbr_unsigned(nb / 10);
		count += ft_putnbr_unsigned(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}
