/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:13:49 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/12 00:48:07 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			*pr_error(void)
{
	ft_putstr("error\n");
	exit(0);
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
	if (dot != 12 || shrp != 4 || (buff[i - 1] != '\n' && buff[i - 2] != '\n')
			|| endl < 4 || endl > 5 || buff[0] == '\n')
		return (0);
	return (1);
}

void			dfs_connetivity_check(t_tetlst *tets, int *flag, int st,
																int *con_num)
{
	int			i;

	*con_num = *con_num + 1;
	i = -1;
	flag[st] = 1;
	while (++i < TET_SIZE)
	{
		if (!flag[i] &&
				(ABS(tets->x[st] - tets->x[i]) +
				ABS(tets->y[st] - tets->y[i])) == 1)
			dfs_connetivity_check(tets, flag, i, con_num);
	}
}

int				blocks_are_connected(t_tetlst *tets)
{
	int			con_num;
	int			flag[TET_SIZE];

	con_num = 0;
	zero_arr(flag, 0, TET_SIZE);
	dfs_connetivity_check(tets, flag, 0, &con_num);
	if (con_num != TET_SIZE)
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
		if (!(blocks_are_connected(tmpl)))
			return ((int)pr_error());
		tmpl = tmpl->next;
	}
	return (1);
}
