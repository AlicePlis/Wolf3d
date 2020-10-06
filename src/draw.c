/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:34:28 by student           #+#    #+#             */
/*   Updated: 2020/09/13 17:34:33 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_put_pixel(char *img_data, int x, int y, int color)
{
	((int*)img_data)[x + HEIGHT * y * 2] = color;
}

int			get_color(t_prog *data, int x, int y, int i)
{
	return (*(unsigned int*)(data->pict_addr[i] +
	y * data->pict_line_length + x * 4));
}

static void	ft_draw_sell_flor(t_prog *a)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = HEIGHT - 1;
		while (++x < HEIGHT * 2)
			ft_put_pixel(a->img_data, x, y,
					(255 - y / 2) << 16 | (255 - y / 2) << 8);
	}
	y = (HEIGHT / 2) - 1;
	while (++y < HEIGHT)
	{
		x = HEIGHT - 1;
		while (++x < HEIGHT * 2)
			ft_put_pixel(a->img_data, x, y,
					(y / 10) << 16 | (y / 10) << 8 | (y / 10));
	}
}

void		ft_draw(t_prog *a)
{
	int		x;
	int		y;
	int		color;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (a->data[y][x] == 1)
				color = 255;
			else
				color = 255 << 8;
			ft_put_pixel(a->img_data, x, y, color);
		}
	}
	ft_video_section(a);
	ft_draw_sell_flor(a);
	ft_draw_wall(a);
}
