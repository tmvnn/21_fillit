/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 18:49:54 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/02 23:50:21 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 20
# define TET_SIZE 4

# include "libft/libft.h" //check for compile

# define SF_ALCN(ptr) if (!ptr) return (NULL);

typedef struct      s_tetlst
{
	char            x[TET_SIZE];
	char			y[TET_SIZE];
	char			letter;
	struct s_tetlst   *next;
}                   t_tetlst;

int					ft_sqrt(int nb);
char				*solve_map(t_tetlst *tets, int tet_num);
void				print_map(char *map, int map_size);

#endif
