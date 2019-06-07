/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:14:37 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/25 11:24:08 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoomisocode(int k, t_map *map)
{
	if (k == 78 && map->z > 1)
	{
		map->z -= 2;
		map->s = (WIDTH - (map->z * (map->line - map->row))) / 2;
		map->t = (HEIGHT - (map->z * (map->line + map->row)) / 2) / 2;
	}
	if (k == 69)
	{
		map->z += 2;
		map->s = (WIDTH - (map->z * (map->line - map->row))) / 2;
		map->t = (HEIGHT - (map->z * (map->line + map->row)) / 2) / 2;
	}
}

void	zoomcode(int k, t_map *map)
{
	if (map->jeffrey == 0)
	{
		if (k == 78 && map->z > 1)
		{
			map->z -= 2;
			map->s = (WIDTH - (map->z * (map->line - 1))) / 2;
			map->t = (HEIGHT - (map->z * (map->row - 1))) / 2;
		}
		if (k == 69)
		{
			map->z += 2;
			map->s = (WIDTH - (map->z * (map->line - 1))) / 2;
			map->t = (HEIGHT - (map->z * (map->row - 1))) / 2;
		}
	}
	else
		zoomisocode(k, map);
}

void	movecode(int k, t_map *map)
{
	if (k == 24)
		map->h += 2;
	if (k == 27)
		map->h -= 2;
	if (k == 123)
		map->s = map->s - map->z;
	if (k == 126)
		map->t = map->t - map->z;
	if (k == 124)
		map->s = map->s + map->z;
	if (k == 125)
		map->t = map->t + map->z;
}

int		keycode_fct(int k, t_map *map)
{
	if (k == 34)
	{
		map->s = (WIDTH - (map->z * (map->line - map->row))) / 2;
		map->t = (HEIGHT - (map->z * (map->line + map->row)) / 2) / 2;
		map->jeffrey = 1;
	}
	if (k == 35)
	{
		map->jeffrey = 0;
		map->s = (WIDTH - (map->z * (map->line - 1))) / 2;
		map->t = (HEIGHT - (map->z * (map->row - 1))) / 2;
	}
	if (k == 53)
		exit(1);
	mlx_clear_window(map->mlx, map->win);
	movecode(k, map);
	zoomcode(k, map);
	if (map->jeffrey == 0)
		ft_map(map);
	else
		ft_isometric(map);
	return (0);
}
