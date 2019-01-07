/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:13:49 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/07 22:11:38 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*pr_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int		input_is_valid(void)
{
	return (1);
}

int		tets_is_valid(int tet_num)
{
	if (tet_num < 1 || tet_num > 26)
		return ((int)pr_error());
	return (1);
}
