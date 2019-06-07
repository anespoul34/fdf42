/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_int_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:51:52 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/17 13:36:44 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_sizetab(char **data)
{
	int x;

	x = 0;
	while (data[x])
		x++;
	return (x);
}

int		**ft_create_int_tab(t_list *lst, int row, int line)
{
	int		**tab;
	char	**data;
	int		y;
	int		x;

	y = 0;
	tab = NULL;
	tab = malloc(sizeof(int*) * ft_size_list(lst));
	while (lst)
	{
		data = ft_strsplit(lst->content, ' ');
		x = 0;
		tab[y] = malloc(sizeof(int) * ft_sizetab(data));
		while (data[x])
		{
			tab[y][x] = ft_atoi(data[x]);
			x++;
		}
		y++;
		lst = lst->next;
	}
	return (tab);
}
