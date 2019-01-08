/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:13:49 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/09 01:34:28 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*pr_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int				input_is_valid(char *buff)
{
	int			endl;
	int			dot;
	int			shrp;
	int			i;

	endl = 0;
	dot = 0;
	shrp = 0;
	i = -1;
	while (buff[++i])
	{
		if (buff[i] != '\n' && buff[i] != '.' && buff[i] != '#')
			return (0);
		endl += buff[i] == '\n' ? 1 : 0;
		dot += buff[i] == '.' ? 1 : 0;
		shrp += buff[i] == '#' ? 1 : 0;
	}
	if (dot != 12 || shrp != 4 || (buff[i - 1] != '\n' && buff[i - 2] != '\n'))
		return (0);
	if (endl < 3 || endl > 5 || buff[0] == '\n')
		return (0);
	return (1);
}

void			zero_arr(int *b, int n, size_t len)
{
	while (len)
		b[--len] = n;
}

int			sum_arr(int *b, size_t len)
{
	int			sum;

	sum = 0;
	while (len)
		sum += b[--len];
	return (sum);
}

int				blocks_are_connected(t_tetlst *tets)
{
	int			con_num;
	int			flag[TET_SIZE];
	int			i;
	int			j;

	printf("tet_letter =  %c\n", tets->letter);
	con_num = 0;
	i = 0;
	zero_arr(flag, 0, TET_SIZE);
	flag[0] = 1;
	while (i < TET_SIZE)
	{
		if (flag[i])
		{
			j = 0;
			while (j < TET_SIZE)
			{
				if (!flag[j])
				{
					printf("con_num = %d\n", con_num = ABS(tets->x[i] - tets->x[j]) + ABS(tets->y[i] - tets->y[j]));
					if (con_num == 1)
						flag[j] = 1;
				}
				j++;
			}
		}
		printf("\n");
		i++;
	}
	printf("sum_flag = %d\n", sum_arr(flag, TET_SIZE));
	if (sum_arr(flag, TET_SIZE) != TET_SIZE)
		return (0);
	return (1);
}

int				connetivity_is_valid(t_tetlst *tets, int tet_num)
{
	t_tetlst	*tmpl;

	if (tet_num < 1 || tet_num > 26)
		return ((int)pr_error());
	tmpl = tets;
	while (tmpl)
	{
		//printf("\n");
		//if (!(blocks_are_connected(tmpl)))
			//return ((int)pr_error());
		tmpl = tmpl->next;
	}
	return (1);
}
