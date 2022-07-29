/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:02:56 by rburner           #+#    #+#             */
/*   Updated: 2021/10/13 02:52:15 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t h)
{
	size_t	i;
	void	*ret;

	i = -1;
	ret = str;
	while (h > ++i)
		*(unsigned char *)str++ = (unsigned char)c;
	return (ret);
}
