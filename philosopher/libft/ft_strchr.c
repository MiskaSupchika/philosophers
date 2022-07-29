/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:14:21 by rburner           #+#    #+#             */
/*   Updated: 2021/11/05 20:36:58 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	*pizda;

	i = 0;
	pizda = (char *)str;
	if (ch == '\0')
		return (&pizda[ft_strlen(pizda)]);
	while (str[i] != ch && str[i])
		i++;
	if (i < ft_strlen(str))
		return (&pizda[i]);
	return (NULL);
}
