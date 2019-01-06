/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 18:49:54 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/07 00:57:03 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 20
# define TET_SIZE 4

# include "libft/libft.h" //check for compile
# include <fcntl.h>

# define ALCN_CHECK(ptr) if (!ptr) return (NULL);

typedef struct		s_tetlst
{
	char			x[TET_SIZE];
	char			y[TET_SIZE];
	char			letter;
	struct s_tetlst *next;
}					t_tetlst;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

int					ft_sqrt(int nb);
int					find_start_size(int tet_num);
char				*solve_map(t_tetlst *tets, int tet_num);
int					find_square(t_tetlst *tets, char *map, int map_size);
int					put_tetr(t_tetlst *tets, char *map, int map_size,
																	t_point p);
int					delete_tetr(t_tetlst *tets, char *map, int map_size,
																	t_point p);
void				reset_map(char *map, int map_size);
void				print_map(char *map, int map_size);

#endif
