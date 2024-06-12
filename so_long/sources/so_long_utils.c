/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:34:43 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/11 17:44:35 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	printmap(char**mapfile)
{
	int	line;
	int	colum;

	line = 0;
	while (mapfile[line] != NULL)
	{
		colum = 0;
		while ((mapfile[line])[colum] != '\0')
		{
			write (1, &(mapfile[line])[colum], 1);
			colum++;
		}
		write (1, "\n", 1);
		line++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strchr_inverse(const char *str, int chr)
{
	size_t	i;

	i = 0;
	if (chr > 255)
	{
		chr = chr % 256;
	}
	while (str[i] != '\0')
	{
		if (str[i] != (unsigned char)chr)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == chr)
		return ((char *)&str[i]);
	return (NULL);
}
