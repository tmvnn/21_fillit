/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:20:45 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/05 18:25:37 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char *map, int map_size)
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

void	reset_map(char *map, int map_size)
{
	ft_memset(map, '.', map_size * map_size);
}
