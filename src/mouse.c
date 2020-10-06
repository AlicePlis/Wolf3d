/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:18:20 by student           #+#    #+#             */
/*   Updated: 2020/09/15 14:18:25 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	quit(void *param)
{
	(void)param;
	exit(0);
}

static int	mouse_press(int button, int x, int y, t_prog *a)
{
	if (button == 1)
	{
		if (x >= HEIGHT && x <= HEIGHT * 2 && y >= 0 && y <= HEIGHT)
		{
			a->mouse.button = ON;
			a->mouse.x0 = x;
		}
	}
	return (0);
}

static int	mouse_release(int button, int x, int y, t_prog *a)
{
	(void)x;
	(void)y;
	if (button == 1)
		a->mouse.button = OFF;
	return (0);
}

static int	mouse_move(int x, int y, t_prog *a)
{
	(void)y;
	if (a->mouse.button == ON)
	{
		a->mouse.x = x - a->mouse.x0;
		a->mouse.x0 = x;
		a->one.fi += a->mouse.x / 400;
		if (a->one.fi >= 6.28319 || a->one.fi <= -6.28319)
			a->one.fi = 0;
		ft_draw(a);
		mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->img_ptr, 0, 0);
	}
	return (0);
}

void		mouse_hook(t_prog *a)
{
	mlx_hook(a->win_ptr, 4, 0, mouse_press, a);
	mlx_hook(a->win_ptr, 5, 0, mouse_release, a);
	mlx_hook(a->win_ptr, 6, 0, mouse_move, a);
	mlx_hook(a->win_ptr, 17, 0, quit, (void*)a);
}
