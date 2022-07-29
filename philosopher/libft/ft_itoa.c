/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:46:25 by rburner           #+#    #+#             */
/*   Updated: 2021/10/22 09:23:59 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*s;
	long int	i;
	int			count;

	i = n;
	count = 0;
	while (n && ++count)
		n = n / 10;
	s = ft_calloc(sizeof(char), count + (i < 0) + 1 + (i == 0));
	if (!s)
		return (NULL);
	if (i < 0)
	{
		s[0] = '-';
		count++;
		i *= -1;
	}
	if (i == 0)
		s[0] = '0';
	while (i)
	{
		s[--count] = i % 10 + '0';
		i = i / 10;
	}
	return (s);
}
