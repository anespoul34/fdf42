/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:56:25 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/04 11:27:00 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1600
# define HEIGHT 1000

# include "./libft/includes/libft.h"
# include "minilibx/mlx.h"

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_map
{
	void			*mlx;
	void			*win;
	int				**tab;
	int				line;
	int				row;
	int				s;
	int				h;
	int				z;
	int				t;
	int				max;
	int				min;
	int				jeffrey;
	char			**content;
	struct s_color	c;
	struct s_map	*next;
}					t_map;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	struct s_color	c;
}					t_coord;

typedef struct		s_draw
{
	int				i;
	int				dx;
	int				dy;
	int				x;
	int				y;
	int				xinc;
	int				yinc;
	int				cumul;
}					t_draw;

t_list				*ft_add_list(t_list *lst, char *str);
t_list				*ft_create_list(char *str);
int					intline(char *str);
void				ft_print_int_tab(t_map *map);
int					**ft_create_int_tab(t_list *lst, int row, int line);
t_map				*ft_create_map(t_list *lst);
void				ft_print_list(t_list *lst);
void				ft_check_row(t_map *map, t_coord *p, int x, int y);
void				ft_check_line(t_map *map, t_coord *p, int x, int y);
unsigned long		ft_gtc(t_coord *p, t_coord *p2, int index, int max);
unsigned long		rgb(t_coord *p);
void				get_point_color(t_map *map, t_coord *p);
void				ft_check_isoline(t_map *map, t_coord *p, int x, int y);
void				ft_check_isorow(t_map *map, t_coord *p, int x, int y);
int					ft_map(t_map *map);
int					ft_isometric(t_map *map);
int					keycode_fct(int k, t_map *map);
void				error(int i);

#endif
