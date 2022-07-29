/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 08:25:08 by rburner           #+#    #+#             */
/*   Updated: 2021/10/31 01:46:10 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		i;
	int			c;
	size_t		s;
	size_t		d;

	i = 0;
	s = ft_strlen(src);
	d = ft_strlen(dest);
	c = s + d;
	if (n <= d)
		return (s + n);
	while (src[i] && i < (n - d - 1))
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (c);
}
