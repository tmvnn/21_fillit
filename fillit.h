/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 18:49:54 by lbellona          #+#    #+#             */
/*   Updated: 2019/01/12 00:46:00 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21
# define TET_SIZE 4

# include "libft.h"
# include <fcntl.h>

# define ALCN_CHECK(ptr) if (!ptr) return (0);
# define ABS(number) ((number) > 0 ? (number):-(number))

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

t_tetlst			*ft_create_elem(char letter);
void				ft_list_push_back(t_tetlst **begin_list, t_tetlst *cur_tet);
int					create_tetr(t_tetlst **tets, char *buff, char letter);
t_tetlst			*read_2_lst(int fd, int *tet_num);
char				*solve_map(t_tetlst *tets, int tet_num);
int					find_square(t_tetlst *tets, char *map, int map_size);
int					put_tetr(t_tetlst *tets, char *map, int map_size,
																	t_point p);
int					delete_tetr(t_tetlst *tets, char *map, int map_size,
																	t_point p);
void				print_map(char *map, int map_size);
int					ft_sqrt(int nb);
void				zero_arr(int *b, int n, size_t len);
int					find_start_size(int tet_num);
void				reset_map(char *map, int map_size);
void				*pr_error();
int					input_is_valid(char *buff);
void				dfs_connetivity_check(t_tetlst *tets, int *flag, int st,
																int *con_num);
int					blocks_are_connected(t_tetlst *tets);
int					connetivity_is_valid(t_tetlst *tets, int tet_num);

#endif
