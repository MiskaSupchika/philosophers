/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:44:32 by rburner           #+#    #+#             */
/*   Updated: 2021/10/31 03:20:28 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	char	*s;

	i = ft_strlen(str);
	s = (char *)str;
	if (ch == '\0')
		return (&s[ft_strlen(s)]);
	while (str[i] != ch && i > 0)
		i--;
	if (i >= 0 && str[i] == ch)
		return (&s[i]);
	return (NULL);
}
