/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:39:10 by enoviell          #+#    #+#             */
/*   Updated: 2023/02/06 15:07:12 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	len;

	len = 0;
	while (!s)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (*s)
	{
	len += ft_putchar(*s);
	s++;
	}
	return (len);
}
