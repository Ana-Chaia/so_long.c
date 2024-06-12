/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:46 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/15 19:08:09 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_there_wall(t_maps *mapcontent)
{
	int			line;
	int			colum;

	line = 0;
	colum = 0;
	while (mapcontent->mapfile[line] != NULL)
		line++;
	while (mapcontent->mapfile[0][colum] != '\0')
	{
		if (mapcontent->mapfile[0][colum] != '1')
			return (ft_printf("ERROR\n - upper wall is open\n") * 0);
		if (mapcontent->mapfile[line - 1][colum] != '1')
			return (ft_printf("ERROR\n - lower wall is open\n") * 0);
		colum++;
	}
	while (line - 1 != 0)
	{
		if (mapcontent->mapfile[line - 1][0] != '1')
			return (ft_printf("ERROR\n - left wall is open\n") * 0);
		if (mapcontent->mapfile[line - 1][colum - 1] != '1')
			return (ft_printf("ERROR\n - right wall is open\n") * 0);
		line--;
	}
	return (1);
}

void	flood_fill(t_maps *mapcontent, int row, int col)
{
	if (mapcontent->mapfile[row][col] == '1' ||
			mapcontent->mapfile[row][col] == '3' ||
			mapcontent->mapfile[row][col] == 'S' ||
			mapcontent->mapfile[row][col] == 'F' ||
			mapcontent->mapfile[row][col] == 'H')
		return ;
	mapcontent->mapfile[row][col] = mapcontent->mapfile[row][col] + 3;
	flood_fill(mapcontent, row - 1, col);
	flood_fill(mapcontent, row + 1, col);
	flood_fill(mapcontent, row, col - 1);
	flood_fill(mapcontent, row, col + 1);
}

int	check_flood(t_maps *mapcontent)
{
	return (is_there_chr(mapcontent, "3SFH01",
			"ERROR\n - exit or collectible not accessible\n"));
}

void	free_matrix(t_maps *mapcontent)
{
	int	row;

	row = 0;
	while (mapcontent->mapfile[row] != NULL)
	{
		free(mapcontent->mapfile[row]);
		row++;
	}
	free(mapcontent->mapfile);
}

int	is_map_valid(t_maps *mapcontent)
{
	if (is_map_rectangular(mapcontent) == 0
		|| is_there_p(mapcontent) == 0
		|| is_there_e(mapcontent) == 0
		|| is_there_c(mapcontent) == 0
		|| is_there_chr (mapcontent, "01CEP", "ERROR\n - there is" \
		" distinct chr\n") == 0
		|| is_there_wall(mapcontent) == 0)
	{
		free_matrix(mapcontent);
		return (0);
	}
	flood_fill(mapcontent, mapcontent->player_line, mapcontent->player_colum);
	if (check_flood (mapcontent) == 0)
	{
		free_matrix(mapcontent);
		return (0);
	}
	x_flood_fill(mapcontent, mapcontent->player_line, mapcontent->player_colum);
	return (1);
}
