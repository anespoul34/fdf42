/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:42:13 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/17 13:35:14 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned long	rgb(t_coord *p)
{
	return ((p->c.r & 0xff) << 16) + ((p->c.g & 0xff) << 8) + (p->c.b & 0xff);
}

void			get_point_color(t_map *map, t_coord *p)
{
	int		d;

	d = map->max - map->min;
	if (p->z == map->min)
	{
		p->c.r = 255;
		p->c.g = 204;
		p->c.b = 102;
	}
	else
	{
		(d == 0) ? d = 1 : d;
		p->c.r = (p->z - map->min) * ((102 - 255) / d) + 255;
		p->c.g = (p->z - map->min) * ((0 - 204) / d) + 204;
		p->c.b = (p->z - map->min) * ((102 - 102) / d) + 102;
	}
}

unsigned long	ft_gtc(t_coord *p, t_coord *p2, int index, int max)
{
	int r;
	int g;
	int b;

	r = ((p2->c.r - p->c.r) * ((index * 100) / max)) / 100 + p->c.r;
	g = ((p2->c.g - p->c.g) * ((index * 100) / max)) / 100 + p->c.g;
	b = ((p2->c.b - p->c.b) * ((index * 100) / max)) / 100 + p->c.b;
	return ((r) << 16) + ((g) << 8) + (b);
}
