/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:20:45 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/14 20:56:52 by lbellona         ###   ########.fr       */
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

int		ft_sqrt(int nb)
{
	int	i;

	i = -1;
	while (++i <= nb)
	{
		if (i * i >= nb)
			return (i);
		if (i > 46430)
			break ;
	}
	return (0);
}

void	zero_arr(int *b, int n, size_t len)
{
	while (len)
		b[--len] = n;
}

int		find_start_size(int tet_num)
{
	return (ft_sqrt(TET_SIZE * tet_num));
}

void	reset_map(char *map, int map_size)
{
	ft_memset(map, '.', map_size);
}
