/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:52:06 by enoviell          #+#    #+#             */
/*   Updated: 2023/02/06 15:18:06 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int nbr)
{
	long long int	n;
	int				len;

	n = nbr;
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += ft_putchar('-');
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
	}
	len += ft_putchar((n % 10) + 48);
	return (len);
}

int	ft_printnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len += ft_putnbr(nbr);
	return (len);
}

int	ft_printunsigned(unsigned int unsnbr)
{
	int	len;

	len = 0;
	if (unsnbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len += ft_putnbr(unsnbr);
	return (len);
}
