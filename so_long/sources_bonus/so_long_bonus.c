/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:08:47 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/14 16:43:30 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_tmaps(t_maps *mapcontent)
{
	mapcontent->mapfile = NULL;
	mapcontent->filecontent = NULL;
	mapcontent->player_line = 0;
	mapcontent->player_colum = 0;
	mapcontent->movements_count = 0;
	mapcontent->collectibles_count = 0;
	mapcontent->collectibles_taken = 0;
	mapcontent->player_count = 0;
}

void	init_tgame( t_game *gamecontent)
{
	gamecontent->mlx_ptr = NULL;
	gamecontent->texture_wallpaper = NULL;
	gamecontent->texture_wall = NULL;
	gamecontent->texture_collectible = NULL;
	gamecontent->texture_exit = NULL;
	gamecontent->texture_player = NULL;
	gamecontent->texture_stepsign = NULL;
	gamecontent->texture_villain = NULL;
	gamecontent->image_wallpaper = NULL;
	gamecontent->image_wall = NULL;
	gamecontent->image_collectible = NULL;
	gamecontent->image_exit = NULL;
	gamecontent->image_player = NULL;
	gamecontent->image_stepnum = NULL;
	gamecontent->image_stepsign = NULL;
	gamecontent->image_villain = NULL;
	gamecontent->villain_count = 0;
	gamecontent->col = 0;
	gamecontent->line = 0;
	gamecontent->mapstruct = NULL;
}

int	main(int argc, char **argv)
{
	t_maps	mapcontent;
	t_game	gamecontent;

	if (argc != 2)
		ft_printf("ERROR - nbr of arguments \n");
	else
	{
		if (ft_file_validation_bonus(argv, &mapcontent) == 0)
			return (0);
		gamecontent.mapstruct = &mapcontent;
		mapcontent.mapfile = ft_split(mapcontent.filecontent, '\n');
		free (mapcontent.filecontent);
		if (mapcontent.mapfile == NULL)
			return (0);
		if (is_map_valid (&mapcontent) == 0)
			return (0);
		mapcontent.movements_count = 0;
		gamecontent.villain_count = 0;
		ft_printf("Steps:%d\n", mapcontent.movements_count);
		if (game_on(&gamecontent, &mapcontent) == 0)
			return (0);
	}
	return (0);
}
