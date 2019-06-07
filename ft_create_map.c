/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:50:42 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/31 12:06:59 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		intmax(t_map *map)
{
	int x;
	int y;
	int z;

	y = 0;
	z = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->line)
		{
			if (map->tab[y][x] > z)
				z = map->tab[y][x];
			x++;
		}
		y++;
	}
	return (z);
}

int		intmin(t_map *map)
{
	int x;
	int y;
	int z;

	y = 0;
	z = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->line)
		{
			if (map->tab[y][x] < z)
				z = map->tab[y][x];
			x++;
		}
		y++;
	}
	return (z);
}

int		intline(char *str)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (str[x])
	{
		if (str[x] >= 48 && str[x] <= 57)
		{
			while (str[x] >= 48 && str[x] <= 57 && str[x] != '\0')
				x++;
			count++;
		}
		if (str[x] == '\0')
			return (count);
		x++;
	}
	return (count);
}

int		map_z(int row, int line)
{
	double x;
	double y;

	x = (double)(WIDTH / line);
	y = (double)(HEIGHT / row);
	if (x > y)
		return (y);
	else
		return (x);
}

t_map	*ft_create_map(t_list *lst)
{
	int		x;
	int		y;
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->mlx = mlx_init();
	map->row = ft_size_list(lst);
	map->line = intline(lst->content);
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "mlx_42");
	map->tab = ft_create_int_tab(lst, map->row, map->line);
	map->z = map_z(map->row, map->line) / 2;
	map->s = (WIDTH - (map->z * (map->line - 1))) / 2;
	map->t = (HEIGHT - (map->z * (map->row - 1))) / 2;
	map->max = intmax(map);
	map->min = intmin(map);
	map->h = 1;
	map->jeffrey = 0;
	return (map);
}
