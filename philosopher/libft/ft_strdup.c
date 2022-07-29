/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:26:11 by rburner           #+#    #+#             */
/*   Updated: 2021/10/31 05:54:20 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*str2;

	str2 = malloc((ft_strlen(str1) + 1) * sizeof(char));
	if (!(str2))
		return (NULL);
	str2 = ft_memcpy(str2, str1, ft_strlen(str1) + 1);
	return (str2);
}
