/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:31:31 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/05 19:31:41 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			delete_tetr(t_tetlst *tets, char *map, int map_size, t_point p)
{
	int		i;
	int		dx;
	int		dy;
	int		pos;

	i = -1;
	while (++i < TET_SIZE)
	{
		dx = p.x + tets->x[i];
		dy = p.y + tets->y[i];
		pos = dx + map_size * dy;
		if ((dx > map_size - 1) || (dx < 0) ||
				(dy > map_size - 1) || (dy < 0))
			return (0);
		if (map[pos] != tets->letter)
			return (0);
		map[pos] = '.';
	}
	return (1);
}

int			put_tetr(t_tetlst *tets, char *map, int map_size, t_point p)
{
	int		i;
	int		dx;
	int		dy;
	int		pos;

	i = -1;
	while (++i < TET_SIZE)
	{
		dx = p.x + tets->x[i];
		dy = p.y + tets->y[i];
		pos = dx + map_size * dy;
		if ((dx > map_size - 1) || (dx < 0) ||
				(dy > map_size - 1) || (dy < 0))
			return (0);
		if (map[pos] != '.')
			return (0);
		map[pos] = tets->letter;
	}
	return (1);
}

int			find_square(t_tetlst *tets, char *map, int map_size)
{
	t_point p;

	if (!tets)
		return (1);
	/* ft_putchar(tets->letter);
	 * ft_putchar('\n');
	 * print_map(map, map_size);
	 * ft_putchar('\n');*/
	p.y = -1;
	while (++p.y < map_size)
	{
		p.x = -1;
		while (++p.x < map_size)
		{
			if (put_tetr(tets, map, map_size, p))
				if (find_square(tets->next, map, map_size))
					return (1);
			delete_tetr(tets, map, map_size, p);
		}
	}
	return (0);
}

char		*solve_map(t_tetlst *tets, int tet_num)
{
	int		map_size;
	char	*map;

	map_size = ft_sqrt(TET_SIZE * tet_num);
	while (1)
	{
		ALCN_CHECK((map = ft_strnew(map_size * map_size)));
		reset_map(map, map_size * map_size);
		if (find_square(tets, map, map_size))
			break ;
		ft_strdel(&map);
	}
	print_map(map, map_size);
	return (NULL);
}
