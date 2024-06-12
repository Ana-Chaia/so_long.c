/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:03:23 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/11 13:03:36 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	x_flood_fill(t_maps *mapcontent, int row, int col)
{
	if (mapcontent->mapfile[row][col] == '1' ||
			mapcontent->mapfile[row][col] == '0' ||
			mapcontent->mapfile[row][col] == 'P' ||
			mapcontent->mapfile[row][col] == 'C' ||
			mapcontent->mapfile[row][col] == 'E')
		return ;
	mapcontent->mapfile[row][col] = mapcontent->mapfile[row][col] - 3;
	x_flood_fill(mapcontent, row - 1, col);
	x_flood_fill(mapcontent, row + 1, col);
	x_flood_fill(mapcontent, row, col - 1);
	x_flood_fill(mapcontent, row, col + 1);
}
