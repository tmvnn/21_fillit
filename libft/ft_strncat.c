/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:23:22 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/04 00:08:36 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *s1p;

	s1p = s1;
	s1p += ft_strlen(s1p);
	while ((*s1p = *s2++) != 0 && n--)
		s1p++;
	*s1p = 0;
	return (s1);
}