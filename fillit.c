/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 20:10:35 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/07 00:56:40 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void			*pr_error()
{
	ft_putstr("error\n");
	return (0);
}

int				input_is_valid()
{
	return (1);
}

t_tetlst			*ft_create_elem(char letter)
{
	t_tetlst			*newlist;

	if ((newlist = (t_tetlst*)malloc(sizeof(t_tetlst))))
	{
		newlist->next = NULL;
		newlist->letter = letter;
	}
	return (newlist);
}

void			ft_list_push_back(t_tetlst **begin_list, char letter)
{
	t_tetlst		*tmpptr;

	if (*begin_list == NULL)
		*begin_list = ft_create_elem(letter);
	else
	{
		tmpptr = *begin_list;
		while (tmpptr->next)
			tmpptr = tmpptr->next;
		tmpptr->next = ft_create_elem(letter);
	}
}

t_tetlst        *create_tetr(char *buff, char letter)
{
	t_tetlst	*tets;
	int			ii;
	int			i;
	int			j;
	t_point		delt;

	ii = -1;
	j = -1;
	i = 0;
	tets = NULL;
	ft_list_push_back(&tets, letter);
	while (buff[++ii])
	{
		if (buff[ii] == '#')
		{
			if (!++j)
			{
				delt.x = i % TET_SIZE;
				delt.y = i / TET_SIZE;
			}
			printf("%d", tets->x[j] = i % TET_SIZE - delt.x);
			printf("%d\n", tets->y[j] = i / TET_SIZE - delt.y);
		}
		i = buff[ii] == '\n' ? i : i + 1;
	}

	//tets = (t_tetlst*)malloc(sizeof(t_tetlst));
	//tets->letter = letter;
	/*
	tmp = tets;
	tmp->x[0] = 0;
	tmp->y[0] = 0;
	tmp->x[1] = 0;
	tmp->y[1] = 1;
	tmp->x[2] = 0;
	tmp->y[2] = 2;
	tmp->x[3] = 0;
	tmp->y[3] = 3;
	*/

	return (tets);
}

t_tetlst		*read_2_lst(int fd, int *tet_num)
{
	t_tetlst	*tets;
	//t_tetlst	*tmp;
	char 		buff[BUFF_SIZE + 1];
	int			size;
	int			i;

	i = 0;
	tets = NULL;
	while ((size = read(fd, buff, BUFF_SIZE)))
	{
		buff[size] = '\0';
		if (!(input_is_valid()))
			return ((t_tetlst *)pr_error());
		ALCN_CHECK((tets = create_tetr(buff, i + 65))); // ASCII
		*tet_num = ++i;
	}
	close(fd);
	return (tets);
}

int				main(int argc, char **argv)
{
	int			fd;
	int			tet_num;
	t_tetlst	*tets;

	if (argc != 2)
		ft_putstr("usage: binary_file tetraminos_file\n");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return ((int)pr_error());
		if ((tets = read_2_lst(fd, &tet_num)))
		{
			solve_map(tets, tet_num);
			//free(tets); ???
		}
	}
	return (0);
}
