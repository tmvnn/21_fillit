/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 20:10:35 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/09 01:34:31 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetlst		*ft_create_elem(char letter)
{
	t_tetlst	*newlist;

	if ((newlist = (t_tetlst*)malloc(sizeof(t_tetlst))))
	{
		newlist->next = NULL;
		newlist->letter = letter;
	}
	return (newlist);
}

void			ft_list_push_back(t_tetlst **begin_list, t_tetlst *cur_tet)
{
	t_tetlst	*tmpptr;

	if (*begin_list == NULL)
		*begin_list = cur_tet;
	else
	{
		tmpptr = *begin_list;
		while (tmpptr->next)
			tmpptr = tmpptr->next;
		tmpptr->next = cur_tet;
	}
}

int				create_tetr(t_tetlst **tets, char *buff, char letter)
{
	int			m_iter;
	int			j;
	t_point		delt;
	t_tetlst	*cur_tet;

	j = -1;
	m_iter = 0;
	ALCN_CHECK((cur_tet = ft_create_elem(letter)));
	while (*buff)
	{
		if (*buff == '#')
		{
			if (!++j)
			{
				delt.x = m_iter % TET_SIZE;
				delt.y = m_iter / TET_SIZE;
			}
			cur_tet->x[j] = m_iter % TET_SIZE - delt.x;
			cur_tet->y[j] = m_iter / TET_SIZE - delt.y;
			//printf("%d", cur_tet->x[j] = m_iter % TET_SIZE - delt.x);
			//printf("%d\n",cur_tet->y[j] = m_iter / TET_SIZE - delt.y);
		}
		m_iter = *buff++ == '\n' ? m_iter : m_iter + 1;
	}
	//printf("\n"); //DELETE
	ft_list_push_back(tets, cur_tet);
	return (1);
}

t_tetlst		*read_2_lst(int fd, int *tet_num)
{
	t_tetlst	*tets;
	char		buff[BUFF_SIZE + 1];
	int			size;
	int			i;

	i = 0;
	tets = NULL;
	while ((size = read(fd, buff, BUFF_SIZE)))
	{
		buff[size] = '\0';
		if (!(input_is_valid(buff)))
			return (0);
		ALCN_CHECK((create_tetr(&tets, buff, (i + 65))));
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
		ft_putstr("usage: ./fillit [tetraminos_file]\n");
	else
	{
		//int t = 3;
		//printf("%d\n", ABS(-5 - 2 * t) + ABS(t + t * (+2)) - ABS(12));
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return ((int)pr_error());
		if ((tets = read_2_lst(fd, &tet_num)))
		{
			if (connetivity_is_valid(tets, tet_num))
				solve_map(tets, tet_num);
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
