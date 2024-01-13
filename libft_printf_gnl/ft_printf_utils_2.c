/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:13:23 by orhaddao          #+#    #+#             */
/*   Updated: 2023/11/26 13:13:32 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, char c)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_puthex(nb / 16, c);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	print_hex(unsigned long n, size_t digits)
{
	int	count;

	count = 0;
	if (digits > 0)
	{
		count += print_hex(n / 16, digits - 1);
		count += ft_puthex(n % 16, 'x');
	}
	return (count);
}

int	putptr(void *ptr)
{
	int				count;
	unsigned long	num;
	size_t			num_digits;
	unsigned long	temp;

	count = 0;
	if (!(ptr))
	{
		ft_putstr("(nil)");
		return (5);
	}
	count += ft_putstr("0x");
	num = (unsigned long) ptr;
	num_digits = 0;
	temp = num;
	while (temp != 0)
	{
		temp = temp / 16;
		num_digits++;
	}
	count += print_hex(num, num_digits);
	return (count);
}
