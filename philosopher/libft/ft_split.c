/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 05:18:15 by rburner           #+#    #+#             */
/*   Updated: 2022/01/25 06:30:43 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countw(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*world_output(char const *str, char c)
{
	int		i;
	char	*world;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	world = malloc(sizeof(char) * (i + 1));
	if (!world)
		return ((void *) NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		world[i] = str[i];
		i++;
	}
	world[i] = '\0';
	return (world);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		w;
	char	**s1;

	if (!s)
		return (NULL);
	w = countw(s, c);
	s1 = calloc(sizeof(char *), (w + 2));
	if (!s1)
		return (NULL);
	i = 0;
	w = -1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			s1[++w] = world_output(s + i, c);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	s1[++w] = 0;
	return (s1);
}
