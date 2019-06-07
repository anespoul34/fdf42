/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:32:46 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/17 13:42:26 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list		*ft_create_list(char *str)
{
	t_list	*lst;

	lst = ft_memalloc(sizeof(t_list));
	lst->content_size = intline(str);
	lst->content = ft_strdup(str);
	lst->next = NULL;
	return (lst);
}

t_list		*ft_add_list(t_list *lst, char *str)
{
	t_list	*begin_list;

	begin_list = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = ft_create_list(str);
	return (begin_list);
}
