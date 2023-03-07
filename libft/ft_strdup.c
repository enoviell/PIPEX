/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:03:50 by enoviell          #+#    #+#             */
/*   Updated: 2023/01/25 11:14:38 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(src) + 1;
	dup = malloc(len);
	i = 0;
	if (!dup)
		return (NULL);
	while (src[i] != '\0')
	{
		dup[i] = src [i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
