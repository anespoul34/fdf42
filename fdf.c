/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:34:26 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/30 13:43:52 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_map(t_map *map)
{
	int		x;
	int		y;
	t_coord	*p;

	p = malloc(sizeof(t_coord));
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->line)
		{
			p->z = map->tab[y][x];
			p->x = x * map->z + map->tab[y][x] * map->h;
			p->y = y * map->z - map->tab[y][x] * map->h;
			get_point_color(map, p);
			if (x < map->line - 1)
				ft_check_line(map, p, x, y);
			if (y < map->row - 1)
				ft_check_row(map, p, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_isometric(t_map *map)
{
	int		x;
	int		y;
	t_coord	*p;

	p = malloc(sizeof(t_coord));
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->line)
		{
			p->z = map->tab[y][x];
			p->x = x * map->z - map->tab[y][x] * map->h;
			p->y = y * map->z - map->tab[y][x] * map->h;
			get_point_color(map, p);
			if (x < map->line - 1)
				ft_check_isoline(map, p, x, y);
			if (y < map->row - 1)
				ft_check_isorow(map, p, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_init(t_map *map)
{
	ft_map(map);
	mlx_key_hook(map->win, keycode_fct, map);
	mlx_loop(map->mlx);
}

void	ft_check_map(t_list *lst)
{
	int i;

	i = 0;
	if (!lst)
	{
		error(0);
		exit(1);
	}
	while (lst->content)
	{
		while (lst->content[i])
		{
			if (lst->content[i] > 57 || (lst->content[i] \
						< 48 && lst->content[i] != 32 && lst->content[i] != 45))
				error(1);
			i++;
		}
		if (!lst->next)
			return ;
		if (lst->content_size != lst->next->content_size)
			error(1);
		i = 0;
		lst = lst->next;
	}
}

int		main(int ac, char **av)
{
	t_list	*lst;
	t_map	*map;
	char	*line;
	int		fd;
	int		ret;

	lst = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			error(1);
		if (!lst)
			lst = ft_create_list(line);
		else
			lst = ft_add_list(lst, line);
	}
	ft_check_map(lst);
	close(fd);
	map = ft_create_map(lst);
	ft_init(map);
	return (0);
}
