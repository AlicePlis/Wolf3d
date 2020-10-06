/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:40:13 by student           #+#    #+#             */
/*   Updated: 2020/09/13 17:40:17 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_put_wall_pixel(t_prog *a, int x, int y, int h)
{
	int color;

	color = 30 << 16 | 30 << 8 | 30;
	if (a->walls[x - HEIGHT].x % 64 == 0 && a->walls[x - HEIGHT].y % 64 != 0 &&
	a->walls[x - HEIGHT].y % 64 != 63)
		color = get_color(a, a->walls[x - HEIGHT].y % 64, 64 *
		(y - (HEIGHT - h) / 2) / h, 0);
	if (a->walls[x - HEIGHT].x % 64 == 63 && a->walls[x - HEIGHT].y
	% 64 != 0 && a->walls[x - HEIGHT].y % 64 != 63)
		color = get_color(a, a->walls[x - HEIGHT].y % 64, 64 *
		(y - (HEIGHT - h) / 2) / h, 2);
	if (a->walls[x - HEIGHT].y % 64 == 0 && a->walls[x - HEIGHT].x %
	64 != 0 && a->walls[x - HEIGHT].x % 64 != 63)
		color = get_color(a, a->walls[x - HEIGHT].x % 64, 64 *
		(y - (HEIGHT - h) / 2) / h, 1);
	if (a->walls[x - HEIGHT].y % 64 == 63 && a->walls[x - HEIGHT].x %
	64 != 0 && a->walls[x - HEIGHT].x % 64 != 63)
		color = get_color(a, a->walls[x - HEIGHT].x % 64, 64 *
		(y - (HEIGHT - h) / 2) / h, 3);
	ft_put_pixel(a->img_data, x, y, color);
}

void		ft_draw_wall(t_prog *a)
{
	int		x;
	int		y;
	int		h;
	int		y_fin;
	int		y_st;

	x = HEIGHT - 1;
	while (++x < HEIGHT * 2)
	{
		h = (int)((HEIGHT * 64 / a->dist[x - HEIGHT]) /
				cosf((511.5 - (x - HEIGHT)) * 1.1 / 1023));
		h = (int)((HEIGHT * 64 / a->walls[x - HEIGHT].dist) /
				cosf((511.5 - (x - HEIGHT)) * 1.1 / 1023));
		y_st = (HEIGHT - h) / 2;
		y_fin = y_st + h;
		if (h > HEIGHT - 1)
		{
			y_st = 0;
			y_fin = HEIGHT - 1;
		}
		y = y_st - 1;
		while (++y < y_fin)
			ft_put_wall_pixel(a, x, y, h);
	}
}
