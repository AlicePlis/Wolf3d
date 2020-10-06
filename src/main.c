/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:09:02 by student           #+#    #+#             */
/*   Updated: 2020/09/13 17:09:09 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_mlx(t_prog *a)
{
	a->mlx_ptr = mlx_init();
	a->win_ptr = mlx_new_window(a->mlx_ptr, HEIGHT * 2, HEIGHT, "ku - ku");
	a->img_ptr = mlx_new_image(a->mlx_ptr, HEIGHT * 2, HEIGHT);
	a->img_data = mlx_get_data_addr(a->img_ptr, &a->bits_per_pixel,
			&a->size_line, &a->endian);
	a->picture[0] = mlx_xpm_file_to_image(a->mlx_ptr, "./textures/wood.xpm",
			&a->pict_widht, &a->pict_heith);
	a->pict_addr[0] = mlx_get_data_addr(a->picture[0], &a->pict_bits_per_pixel,
			&a->pict_line_length, &a->pict_endian);
	a->picture[1] = mlx_xpm_file_to_image(a->mlx_ptr,
			"./textures/bluestone.xpm", &a->pict_widht, &a->pict_heith);
	a->pict_addr[1] = mlx_get_data_addr(a->picture[1], &a->pict_bits_per_pixel,
			&a->pict_line_length, &a->pict_endian);
	a->picture[2] = mlx_xpm_file_to_image(a->mlx_ptr,
			"./textures/colorstone.xpm", &a->pict_widht, &a->pict_heith);
	a->pict_addr[2] = mlx_get_data_addr(a->picture[2], &a->pict_bits_per_pixel,
			&a->pict_line_length, &a->pict_endian);
	a->picture[3] = mlx_xpm_file_to_image(a->mlx_ptr, "./textures/redbrick.xpm",
			&a->pict_widht, &a->pict_heith);
	a->pict_addr[3] = mlx_get_data_addr(a->picture[3], &a->pict_bits_per_pixel,
			&a->pict_line_length, &a->pict_endian);
}

int				main(int argc, char **argv)
{
	t_prog	a;

	if (argc == 2)
	{
		if (!(ft_full_data(&a, argv[1])))
			ft_exit("Not valid file!");
		init_mlx(&a);
		ft_draw(&a);
		mlx_put_image_to_window(a.mlx_ptr, a.win_ptr, a.img_ptr, 0, 0);
		mlx_hook(a.win_ptr, 2, 0, press, (void*)&a);
		mouse_hook(&a);
		mlx_loop(a.mlx_ptr);
	}
	ft_exit("usage: wolf3d map");
}
