/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isorow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:24:04 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/17 13:41:24 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vec_row(t_map *map, t_coord *p, t_coord *py)
{
	int j;

	j = p->y;
	while (j < py->y)
	{
		mlx_pixel_put(map->mlx, map->win, (p->x - j) + map->s,\
				(j + p->x) / 2 + map->t, rgb(p));
		j++;
	}
}

void	x_yisorow(t_map *e, t_draw *d, t_coord *p, t_coord *py)
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
		mlx_pixel_put(e->mlx, e->win, (d->x - d->y) + e->s, \
				(d->y + d->x) / 2 + e->t, ft_gtc(p, py, d->i, d->dx));
		d->i++;
	}
}

void	y_xisorow(t_map *e, t_draw *d, t_coord *p, t_coord *py)
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
		mlx_pixel_put(e->mlx, e->win, (d->x - d->y) + e->s, \
				(d->y + d->x) / 2 + e->t, ft_gtc(p, py, d->i, d->dy));
		d->i++;
	}
}

void	vec_row_3d(t_map *map, t_coord *p, t_coord *py)
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
		x_yisorow(map, d, p, py);
	else
		y_xisorow(map, d, p, py);
	free(d);
}

void	ft_check_isorow(t_map *map, t_coord *p, int x, int y)
{
	t_coord *py;

	py = malloc(sizeof(t_coord));
	py->z = map->tab[y + 1][x];
	py->x = x * map->z - py->z * map->h;
	py->y = (y + 1) * map->z - py->z * map->h;
	get_point_color(map, py);
	if (y == (map->row - 1))
	{
		free(py);
		return ;
	}
	if (p->z == py->z)
		vec_row(map, p, py);
	else
		vec_row_3d(map, p, py);
	free(py);
}
