/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:06:22 by anespoul          #+#    #+#             */
/*   Updated: 2015/12/26 18:14:16 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_swap_list(t_list *tetrim)
{
	t_list *begin_list;
	t_list *tmp;

	begin_list = tetrim;
	tmp = NULL;
	while (tetrim->next->next && tetrim->next->next->content)
	{
		tetrim = tetrim->next;
	}
	tmp = tetrim->next;
	tmp->next = begin_list;
	begin_list = tmp;
	tetrim->next = NULL;
	return (begin_list);
}
