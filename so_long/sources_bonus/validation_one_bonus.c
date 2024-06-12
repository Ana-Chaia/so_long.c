/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:58:15 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/12 15:59:44 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	is_map_rectangular(t_maps *mapcontent)
{
	int		line;
	size_t	firstline_size;

	line = 0;
	firstline_size = ft_strlen(mapcontent->mapfile[line]);
	while (mapcontent->mapfile[line] != NULL)
	{
		if (ft_strlen(mapcontent->mapfile[line]) == firstline_size)
			line++;
		else
		{
			ft_printf("ERROR\n - map is not rectangular\n");
			return (0);
		}
	}
	return (1);
}

int	is_there_p(t_maps *mapcontent)
{
	int	line;
	int	colum;

	line = 0;
	mapcontent->player_count = 0;
	while (mapcontent->mapfile[line] != NULL)
	{
		colum = 0;
		while ((mapcontent->mapfile[line])[colum] != '\0')
		{
			if ((mapcontent->mapfile[line])[colum++] == 'P' &&
			++mapcontent->player_count > 1)
				return (ft_printf("ERROR\n - too many players\n") * 0);
			else if ((mapcontent->mapfile[line])[colum -1] == 'P' &&
				mapcontent->player_count == 1)
			{
				mapcontent->player_line = line;
				mapcontent->player_colum = colum -1;
			}
		}
		line++;
	}
	if (mapcontent->player_count == 0)
		return (ft_printf("ERROR\n - there is no player\n") * 0);
	return (1);
}

int	is_there_e(t_maps *mapcontent)
{
	int	line;
	int	colum;
	int	exit_count;

	line = 0;
	exit_count = 0;
	while (mapcontent->mapfile[line] != NULL)
	{
		colum = 0;
		while ((mapcontent->mapfile[line])[colum] != '\0')
			if ((mapcontent->mapfile[line])[colum++] == 'E' &&
				++exit_count > 1)
				return (ft_printf("ERROR\n - too many exits\n") * 0);
		line++;
	}
	if (exit_count == 0)
		return (ft_printf("ERROR\n - there is no exit\n") * 0);
	return (1);
}

int	is_there_c(t_maps *mapcontent)
{
	int	line;
	int	colum;

	line = 0;
	mapcontent->collectibles_count = 0;
	while (mapcontent->mapfile[line] != NULL)
	{
		colum = 0;
		while ((mapcontent->mapfile[line])[colum] != '\0')
		{
			if ((mapcontent->mapfile[line])[colum] == 'C')
				mapcontent->collectibles_count++;
			colum++;
		}
		line++;
	}
	mapcontent->collectibles_taken = mapcontent->collectibles_count;
	if (mapcontent->collectibles_count == 0)
		return (ft_printf("ERROR\n - there are no collectibles\n") * 0);
	return (1);
}

int	is_there_chr(t_maps *mapcontent, const char *str, char *error_message)
{
	int			line;
	int			colum;

	line = 0;
	while (mapcontent->mapfile[line] != NULL)
	{
		colum = 0;
		while ((mapcontent->mapfile[line])[colum] != '\0')
		{
			if (ft_strchr(str, (mapcontent->mapfile[line])[colum]) == NULL)
			{
				return (ft_printf("%s", error_message) * 0);
			}
			colum++;
		}
		line++;
	}
	return (1);
}
