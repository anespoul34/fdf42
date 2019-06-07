/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:43:32 by anespoul          #+#    #+#             */
/*   Updated: 2016/02/23 14:12:48 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_int_tab(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->line)
		{
			ft_putnbr(map->tab[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
