/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:03:02 by rburner           #+#    #+#             */
/*   Updated: 2021/10/21 15:27:03 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*ret;

	i = -1;
	ret = dest;
	if (dest || src)
		while (n > ++i)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (ret);
}
