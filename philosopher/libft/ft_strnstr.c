/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:14:38 by rburner           #+#    #+#             */
/*   Updated: 2021/10/31 03:28:18 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*need)
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		while (need[j] && need[j] == hay[i + j] && i + j < len)
			j++;
		if (j == ft_strlen(need))
			return ((char *)&hay[i]);
		if (!need[j])
			return ((char *)&hay[i]);
		if (!hay[i + j] || i + j == len)
			return (0);
		i++;
		j = 0;
	}
	return (0);
}
