/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:24:18 by enoviell          #+#    #+#             */
/*   Updated: 2023/01/25 11:35:54 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_looplstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *), t_list *new_n)
{
	t_list	*list;

	list = new_n;
	while (lst)
	{
		new_n = ft_lstnew(f(lst->content));
		if (!new_n)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&list, new_n);
	}
	return (list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_n;
	t_list	*ptr;

	if (!f || !lst)
		return (NULL);
	new_n = ft_lstnew(f(lst->content));
	if (!new_n)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	if (lst->next == NULL)
		return (new_n);
	lst = lst->next;
	ptr = ft_looplstmap(lst, f, del, new_n);
	return (ptr);
}
