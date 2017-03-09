/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:03:35 by cserdean          #+#    #+#             */
/*   Updated: 2017/02/15 16:03:36 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *prov_new_list;
	t_list *new_list;

	if (!lst)
		return (NULL);
	if (!(new_list = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new_list = f(lst);
	prov_new_list = new_list;
	while (lst->next)
	{
		prov_new_list->next = f(lst->next);
		prov_new_list = prov_new_list->next;
		lst = lst->next;
	}
	return (new_list);
}
