/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:36:26 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/25 14:04:18 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int i)
{
	t_map *e;

	e = malloc(sizeof(t_map));
	if (i == 1)
	{
		ft_putstr("map error !!!\n");
		exit(1);
	}
	if (i == 0)
	{
		e->mlx = mlx_init();
		e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx_42");
		mlx_key_hook(e->win, keycode_fct, e);
		mlx_loop(e->mlx);
	}
}
