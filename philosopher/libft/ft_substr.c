/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 07:13:51 by rburner           #+#    #+#             */
/*   Updated: 2021/10/28 09:44:55 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	s1 = malloc((len + 1) * sizeof(char));
	if (!s1)
		return (NULL);
	while (s[j])
	{
		if (i < len && j >= start)
		{
			s1[i] = s[j];
			i++;
		}
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
