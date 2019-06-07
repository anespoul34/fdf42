/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:09:07 by anespoul          #+#    #+#             */
/*   Updated: 2015/12/26 18:33:45 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_reverse_list(t_list *tetrim)
{
	t_list	*new_tetrim;
	t_list	*next;

	new_tetrim = NULL;
	while (tetrim)
	{
		next = tetrim->next;
		tetrim->next = new_tetrim;
		new_tetrim = tetrim;
		tetrim = next;
	}
	return (new_tetrim);
}
