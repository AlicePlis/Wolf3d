/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltortill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:06:13 by student           #+#    #+#             */
/*   Updated: 2020/09/11 16:06:26 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define HEIGHT 1024
# define ON 1
# define OFF 0

typedef	struct	s_mouse
{
	int		x0;
	float	x;
	float	button;
}				t_mouse;

typedef	struct	s_pnt
{
	int		x;
	int		y;
	float	dist;
}				t_pnt;

typedef	struct	s_player
{
	t_pnt	place;
	float	fi;
	char	type;
}				t_player;

typedef struct	s_prog
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_player	one;
	void		*picture[4];
	void		*pict_addr[4];
	int			pict_widht;
	int			pict_heith;
	int			pict_line_length;
	int			pict_bits_per_pixel;
	int			pict_endian;
	int			data[HEIGHT][HEIGHT];
	float		dist[HEIGHT];
	t_pnt		walls[HEIGHT];
	t_mouse		mouse;
}				t_prog;

int				ft_full_data(t_prog *a, char *mapname);
int				press(int key, t_prog *a);
void			ft_draw(t_prog *a);
void			ft_draw_wall(t_prog *a);
int				get_color(t_prog *data, int x, int y, int i);
void			ft_put_pixel(char *img_data, int x, int y, int color);
void			ft_video_section(t_prog *a);
int				ft_check_new_place(t_prog *a, int x, int y);
void			mouse_hook(t_prog *a);
void			ft_move(t_prog *a, float fim);
void			ft_rotate(t_prog *a, float fir);
#endif
