/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_row.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:34:20 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/17 13:42:46 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vec_isorow(t_map *map, t_coord *p, t_coord *py)
{
	int j;

	j = p->y;
	while (j < py->y)
	{
		mlx_pixel_put(map->mlx, map->win, p->x + map->s, j + map->t, rgb(p));
		j++;
	}
}

void	x_yrow(t_map *e, t_draw *d, t_coord *p, t_coord *py)
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
				ft_gtc(p, py, d->i, d->dx));
		d->i++;
	}
}

void	y_xrow(t_map *e, t_draw *d, t_coord *p, t_coord *py)
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
				ft_gtc(p, py, d->i, d->dy));
		d->i++;
	}
}

void	vec_isorow_3d(t_map *map, t_coord *p, t_coord *py)
{
	t_draw	*d;

	d = malloc(sizeof(t_draw));
	d->x = p->x;
	d->y = p->y;
	d->dx = py->x - p->x;
	d->dy = py->y - p->y;
	d->xinc = (d->dx > 0) ? 1 : -1;
	d->yinc = (d->dy > 0) ? 1 : -1;
	d->dx = abs(d->dx);
	d->dy = abs(d->dy);
	d->i = 1;
	if (d->dx > d->dy)
		x_yrow(map, d, p, py);
	else
		y_xrow(map, d, p, py);
	free(d);
}

void	ft_check_row(t_map *map, t_coord *p, int x, int y)
{
	t_coord *py;

	py = malloc(sizeof(t_coord));
	py->z = map->tab[y + 1][x];
	py->x = x * map->z + py->z * map->h;
	py->y = (y + 1) * map->z - py->z * map->h;
	get_point_color(map, py);
	if (y == (map->row - 1))
	{
		free(py);
		return ;
	}
	if (p->z == py->z)
		vec_isorow(map, p, py);
	else
		vec_isorow_3d(map, p, py);
	free(py);
}
