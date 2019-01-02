/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/02 23:50:23 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

/*int		tet_parse(char *buff, t_tetlst **tets)
{
	if (*buff)
	{
		while (*buff)
		{
		}
		return (1);
	}
	return (0);
}*/

int		ft_sqrt(int nb)
{
	int		i;

	i = -1;
	while (++i <= nb)
	{
		if (i * i == nb)
			return (i);
		if (i * i > nb)
			return (i);
		if (i > 46430)
			break ;
	}
	return (0);
}

int		main()
{
	//char *buff = {"....\n..##\n.##.\n....\n"};

	t_tetlst *tets;
	t_tetlst *tmp;
	int tet_num;

	tet_num = 0;
	tets = (t_tetlst*)malloc(sizeof(t_tetlst));

	tets->letter = 'A';

	/*tets->x[0] = 0;
	tets->y[0] = 0;
	tets->x[1] = 1;
	tets->y[1] = 0;
	tets->x[2] = -1;
	tets->y[2] = 1;
	tets->x[3] = 0;
	tets->y[3] = 1;
	*/

	tets->x[0] = 0;
	tets->y[0] = 0;
	tets->x[1] = 1;
	tets->y[1] = 0;
	tets->x[2] = 1;
	tets->y[2] = 1;
	tets->x[3] = 1;
	tets->y[3] = 2;

	tmp = (t_tetlst*)malloc(sizeof(t_tetlst));
	tets->next = tmp;
	tmp = tets->next;

	tmp->letter = 'B';
	tmp->x[0] = 0;
	tmp->y[0] = 0;
	tmp->x[1] = 1;
	tmp->y[1] = 0;
	tmp->x[2] = 2;
	tmp->y[2] = 0;
	tmp->x[3] = 3;
	tmp->y[3] = 0;

	tmp->next = (t_tetlst*)malloc(sizeof(t_tetlst));
	tmp = tmp->next;

	tmp->letter = 'C';
	tmp->x[0] = 0;
	tmp->y[0] = 0;
	tmp->x[1] = 0;
	tmp->y[1] = 1;
	tmp->x[2] = 1;
	tmp->y[2] = 1;
	tmp->x[3] = 2;
	tmp->y[3] = 1;

	tmp->next = (t_tetlst*)malloc(sizeof(t_tetlst));
	tmp = tmp->next;

	tmp->letter = 'D';
	tmp->x[0] = 0;
	tmp->y[0] = 0;
	tmp->x[1] = 1;
	tmp->y[1] = 0;
	tmp->x[2] = 1;
	tmp->y[2] = 1;
	tmp->x[3] = 2;
	tmp->y[3] = 1;

	tmp->next = NULL;

	tmp = tets;
	tet_num = 4;

	solve_map(tets, tet_num);
	return (0);
}
