/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:50:17 by enoviell          #+#    #+#             */
/*   Updated: 2023/02/06 15:28:28 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_type(args, str[i + 1]);
			i++;
		}
		else
		len += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (len);
}
