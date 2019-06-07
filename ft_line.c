/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:34:29 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/04 11:25:54 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vec_line(t_map *map, t_coord *p, t_coord *px)
{
	int	i;

	i = p->x;
	while (i < px->x)
	{
		mlx_pixel_put(map->mlx, map->win, i + map->s, p->y + map->t, rgb(p));
		i++;
	}
}

void	x_y(t_map *e, t_draw *d, t_coord *p, t_coord *px)
{
	d->cumul = d->dx / 2;
	while (d->i <= d->dx)
	{
		d->x += d->xinc;
		d->cumul += d->dy;
		if (d->cumul >= d->dx)
		{
			d->cumul -= d->dx;
			d->y += d->yinc;
		}
		mlx_pixel_put(e->mlx, e->win, d->x + e->s, d->y + e->t, \
				ft_gtc(p, px, d->i, d->dx));
		d->i++;
	}
}

void	y_x(t_map *e, t_draw *d, t_coord *p, t_coord *px)
{
	d->cumul = d->dy / 2;
	while (d->i <= d->dy)
	{
		d->y += d->yinc;
		d->cumul += d->dx;
		if (d->cumul >= d->dy)
		{
			d->cumul -= d->dy;
			d->x += d->xinc;
		}
		mlx_pixel_put(e->mlx, e->win, d->x + e->s, d->y + e->t, \
				ft_gtc(p, px, d->i, d->dy));
		d->i++;
	}
}

void	vec_line_3d(t_map *map, t_coord *p, t_coord *px)
{
	t_draw	*d;

	d = malloc(sizeof(t_draw));
	d->x = p->x;
	d->y = p->y;
	d->dx = px->x - p->x;
	d->dy = px->y - p->y;
	d->xinc = (d->dx > 0) ? 1 : -1;
	d->yinc = (d->dy > 0) ? 1 : -1;
	d->dx = abs(d->dx);
	d->dy = abs(d->dy);
	d->i = 1;
	if (d->dx > d->dy)
		x_y(map, d, p, px);
	else
		y_x(map, d, p, px);
	free(d);
}

void	ft_check_line(t_map *map, t_coord *p, int x, int y)
{
	t_coord	*px;

	px = malloc(sizeof(t_coord));
	px->x = (x + 1) * map->z + map->tab[y][x + 1] * map->h;
	px->y = y * map->z - map->tab[y][x + 1] * map->h;
	px->z = map->tab[y][x + 1];
	get_point_color(map, px);
	if (x == (map->line - 1))
	{
		free(px);
		return ;
	}
	if (p->z == px->z)
		vec_line(map, p, px);
	if (p->z != px->z)
		vec_line_3d(map, p, px);
	free(px);
}
