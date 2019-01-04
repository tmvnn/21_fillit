/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:31:31 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/05 00:19:26 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void		print_map(char *map, int map_size)
{
	int i;
	int j;

	i = -1;
	if (map)
		while (++i < map_size)
		{
			j = -1;
			while (++j < map_size)
				ft_putchar(map[i * map_size + j]);
			ft_putchar('\n');
		}
}

void		reset_map(char *map, int map_size)
{
	ft_memset(map, '.', map_size * map_size);
}

int			delete_tetr(t_tetlst *tets, char *map, int map_size, int x, int y)
{
	int i;
	int dx;
	int dy;
	int pos;

	i = -1;
	while (++i < TET_SIZE)
	{
		dx = x + tets->x[i];
		dy = y + tets->y[i];
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

int			put_tetr(t_tetlst *tets, char *map, int map_size, int x, int y)
{
	int i;
	int dx;
	int dy;
	int pos;

	i = -1;
	while (++i < TET_SIZE)
	{
		dx = x + tets->x[i];
		dy = y + tets->y[i];
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

int			paste_tet(t_tetlst *tets, char *map, int map_size)
{
	int mx;
	int my;

	/*
	mx = 2;
	my = 1;
	printf("%d\n", put_tetr(tets, map, map_size, mx, my));
	//delete_tetr(tets, map, map_size, mx, my);
	return (1);
	*/

	if (!tets)
		return (1);
	printf("%c\n", tets->letter);
	print_map(map, map_size);
	printf("\n");

	t_tetlst *tmp;
	tmp = tets;
	//while (tmp)
	{
		my = -1;
		while (++my < map_size)
		{
			mx = -1;
			while (++mx < map_size)
			{
				if (put_tetr(tets, map, map_size, mx, my))
				{
					if (paste_tet(tets->next, map, map_size))
						return (1);
					//return (paste_tet(tets->next, map, map_size));
				}
				//else
				delete_tetr(tets, map, map_size, mx, my);
			}
		}
		//reset_map(map, map_size * map_size);
		//tmp = tmp->next;
	}
	return(0);
}

char		*solve_map(t_tetlst *tets, int tet_num)
{
	int map_size;
	//t_tetlst *tmp;
	char *map;

	map_size = ft_sqrt(TET_SIZE * tet_num);
	while (1)
	{
		ALCN_CHECK((map = ft_strnew(map_size * map_size)));
		reset_map(map, map_size * map_size);

		if (paste_tet(tets, map, map_size))
			break;
		ft_strdel(&map);
		if (map_size++ > 150) //DELETE!
			printf("overload");
	}
	print_map(map, map_size);
	return (NULL);
}
