/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_section.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:45:56 by student           #+#    #+#             */
/*   Updated: 2020/09/13 17:46:04 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_put_line_x(char *img_data, t_pnt *st, t_pnt *fin, int color)
{
	int x;
	int y;
	int step;

	if (fin->x > st->x)
		step = 1;
	else
		step = -1;
	x = st->x;
	while (x != fin->x)
	{
		y = st->y + (fin->y - st->y) * (x - st->x) / (fin->x - st->x);
		ft_put_pixel(img_data, x, y, color);
		x += step;
	}
}

static void		ft_put_line_y(char *img_data, t_pnt *st, t_pnt *fin, int color)
{
	int x;
	int y;
	int step;

	if (fin->y > st->y)
		step = 1;
	else
		step = -1;
	y = st->y;
	while (y != fin->y)
	{
		x = st->x + (fin->x - st->x) * (y - st->y) / (fin->y - st->y);
		ft_put_pixel(img_data, x, y, color);
		y += step;
	}
}

static void		ft_put_line(char *img_data, t_pnt *st, t_pnt *fin, int color)
{
	if ((fin->x - st->x) * (fin->x - st->x) >=
	(fin->y - st->y) * (fin->y - st->y))
	{
		ft_put_line_x(img_data, st, fin, color);
	}
	else
	{
		ft_put_line_y(img_data, st, fin, color);
	}
}

static float	ft_check_ray(t_prog *a, float fi, t_pnt *res)
{
	float	dist;

	dist = 0.0;
	while (a->data[a->one.place.y + (int)(dist * sinf(fi))][a->one.place.x +
	(int)(dist * cosf(fi))] == 0)
	{
		dist += 0.1;
	}
	while (a->data[a->one.place.y + (int)(dist * sinf(fi))][a->one.place.x +
	(int)(dist * cosf(fi))] != 0)
		dist -= 0.01;
	res->y = a->one.place.y + (int)(dist * sinf(fi));
	res->x = a->one.place.x + (int)(dist * cosf(fi));
	return (dist);
}

void			ft_video_section(t_prog *a)
{
	float	fi_st;
	float	fi;
	int		i;

	fi_st = a->one.fi - 0.55;
	i = -1;
	while (++i < HEIGHT)
	{
		fi = fi_st + i * 1.1 / (HEIGHT - 1);
		a->walls[i].dist = ft_check_ray(a, fi, &a->walls[i]);
	}
	i = -1;
	while (++i < HEIGHT - 1)
		if (a->walls[i].dist > 1.1 * a->walls[i - 1].dist && a->walls[i].dist >
		1.1 * a->walls[i + 1].dist)
		{
			fi = fi_st + i * 1.1 / (HEIGHT - 1);
			a->walls[i].dist = (a->walls[i - 1].dist +
					a->walls[i + 1].dist) / 2;
			a->walls[i].y = a->one.place.y + (int)(a->walls[i].dist * sinf(fi));
			a->walls[i].x = a->one.place.x + (int)(a->walls[i].dist * cosf(fi));
		}
	i = -1;
	while (++i < HEIGHT)
		ft_put_line(a->img_data, &a->one.place, &a->walls[i], 0xffffff);
}
