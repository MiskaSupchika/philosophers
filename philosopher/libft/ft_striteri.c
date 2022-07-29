/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 06:05:16 by rburner           #+#    #+#             */
/*   Updated: 2021/10/31 02:29:38 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*lol)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s && i < ft_strlen(s))
	{
		lol(i, &s[i]);
		i++;
	}
}	
