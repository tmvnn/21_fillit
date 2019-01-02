/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:31:31 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/02 23:50:18 by lbellona         ###   ########.fr       */
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

int			put_tetr(t_tetlst *tets, char *map, int map_size, int x, int y)
{
	int i;
	int dx;
	int dy;

	i = -1;
	while (++i < TET_SIZE)
	{
		dx = x + tets->x[i];
		dy = y + tets->y[i];
		if ((dx > map_size - 1) || (dx < 0) ||
				(dy > map_size - 1) || (dy < 0))
			return (0);
		if (map[dx + map_size * dy] != '.')
			return (0);
		map[dx + map_size * dy] = tets->letter;
	}
	return (1);
}

int			paste_tet(t_tetlst *tets, char *map, int map_size)
{
	int mx;
	int my;

	mx = 2;
	my = 1;
	printf("%d\n", put_tetr(tets, map, map_size, mx, my));

	return(1);
}

char		*solve_map(t_tetlst *tets, int tet_num)
{
	/*
	 * Выделить карту размером sqtr(4 * tet_num);
	 *
	 * Беру текущий тетрамин
	 *
	 * Прохожу от начала карты и пытаюсь вставить тетрамин
	 * Если удается вставить
	 * 		выхожу и перехожу к следующему тетрамину
	 * Иначе сдивигаю курсор карты
	 *
	 *  */

	int map_size;
	char *map;
	tets->x[0] = 0;

	map_size = ft_sqrt(TET_SIZE * tet_num);

	SF_ALCN((map = ft_strnew(map_size * map_size)));
	ft_memset(map, '.', map_size * map_size);

	paste_tet(tets, map, map_size);
	print_map(map, map_size);

	return (NULL);
}
