/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltortill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:08:10 by student           #+#    #+#             */
/*   Updated: 2020/09/11 16:08:17 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_place(t_prog *a, int map[16][16])
{
	int		i;
	int		j;
	short	flag;

	flag = 0;
	a->one.place.y = 0;
	a->one.place.x = 0;
	i = -1;
	while (++i < 16)
	{
		j = -1;
		while (++j < 16)
			if (map[i][j] == 5)
			{
				if (flag)
					return (0);
				map[i][j] = 0;
				a->one.place.y = i * 64 + 32;
				a->one.place.x = j * 64 + 32;
				flag = 1;
			}
	}
	if (!a->one.place.y || !a->one.place.x)
		return (0);
	return (1);
}

static int	check_line(char *line, int count)
{
	int		i;

	i = -1;
	if (count == 0 || count == 15)
	{
		while (line[++i])
		{
			if (line[i] != '1' && line[i] != ' ')
				return (0);
		}
	}
	if (line[0] != '1' || line[30] != '1')
		return (0);
	return (1);
}

static int	valid_map(char *mapname)
{
	int		count;
	int		i;
	int		fd;
	char	*line;

	count = 0;
	fd = open(mapname, O_RDONLY, 0);
	while ((i = get_next_line(fd, &line)))
	{
		if (i < 0 || !line)
			return (0);
		if (ft_strlen(line) != 31 || !check_line(line, count))
		{
			free(line);
			return (0);
		}
		free(line);
		count++;
	}
	if (count != 16)
		return (0);
	close(fd);
	return (1);
}

static int	read_map(char *mapname, int map[16][16])
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**cords;

	if (!(valid_map(mapname)))
		return (0);
	i = 0;
	fd = open(mapname, O_RDONLY, 0);
	while (get_next_line(fd, &line) > 0)
	{
		cords = ft_strsplit(line, ' ');
		j = -1;
		while (cords[++j])
		{
			map[i][j] = ft_atoi(cords[j]);
			free(cords[j]);
		}
		free(cords);
		free(line);
		i++;
	}
	return (1);
}

int			ft_full_data(t_prog *a, char *mapname)
{
	int		map[16][16];
	int		i;
	int		j;

	if (!(read_map(mapname, map)))
		return (0);
	if (!(check_place(a, map)))
		return (0);
	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < HEIGHT)
			a->data[i][j] = map[i / 64][j / 64];
	}
	a->one.fi = 3.1415926;
	return (1);
}
