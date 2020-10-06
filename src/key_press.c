/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:24:03 by student           #+#    #+#             */
/*   Updated: 2020/09/13 17:24:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_check_new_place(t_prog *a, int x, int y)
{
	if (a->data[y][x] != 0)
		return (1);
	if (a->data[y - 7][x] != 0)
		return (1);
	if (a->data[y + 7][x] != 0)
		return (1);
	if (a->data[y][x - 7] != 0)
		return (1);
	if (a->data[y][x + 7] != 0)
		return (1);
	if (a->data[y - 7][x - 7] != 0)
		return (1);
	if (a->data[y + 7][x + 7] != 0)
		return (1);
	if (a->data[y + 7][x - 7] != 0)
		return (1);
	if (a->data[y - 7][x + 7] != 0)
		return (1);
	return (0);
}

void		ft_rotate(t_prog *a, float fir)
{
	if (fir == 0.0)
		a->one.fi = 0.0;
	a->one.fi += fir;
	ft_draw(a);
	mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->img_ptr, 0, 0);
}

void		ft_move(t_prog *a, float fim)
{
	int step;
	int x_new;
	int y_new;

	step = 10;
	x_new = a->one.place.x + (int)(step * cosf(fim));
	y_new = a->one.place.y + (int)(step * sinf(fim));
	if (ft_check_new_place(a, x_new, y_new) == 1)
	{
		while (ft_check_new_place(a, x_new, y_new) == 1 && step > 0)
		{
			step -= 1;
			x_new = a->one.place.x + (int)(step * cosf(fim));
			y_new = a->one.place.y + (int)(step * sinf(fim));
		}
	}
	if (step > 0)
	{
		a->one.place.x = x_new;
		a->one.place.y = y_new;
	}
	ft_draw(a);
	mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->img_ptr, 0, 0);
}

int			press(int key, t_prog *a)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		ft_move(a, a->one.fi - 1.5707963);
	if (key == 124)
		ft_move(a, a->one.fi + 1.5707963);
	if (key == 126)
		ft_move(a, a->one.fi);
	if (key == 125)
		ft_move(a, a->one.fi + 3.1415926);
	if (key == 18)
		ft_rotate(a, -1.5707963);
	if (key == 19)
		ft_rotate(a, 1.5707963);
	if (key == 21)
		ft_rotate(a, -0.15707963);
	if (key == 23)
		ft_rotate(a, 0.15707963);
	if (key == 20)
		ft_rotate(a, 0.0);
	if (key == 13)
		ft_move(a, a->one.fi);
	return (0);
}
