/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:44:09 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/25 19:15:16 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_ima_to_win(t_game *gamecontent, t_maps *mapcontent)
{
	int	colum;
	int	line;

	line = 0;
	while (mapcontent->mapfile[line] != NULL)
	{
		colum = 0;
		while (mapcontent->mapfile[line][colum] != '\0')
		{
			put_each_image(gamecontent, mapcontent->mapfile[line][colum],
				colum * WIDTH, line * HEIGHT);
			colum++;
		}
		line++;
	}
}

void	put_player(t_game *gamecontent, t_maps *mapcontent)
{
	int	colum;
	int	line;

	line = 0;
	while (mapcontent->mapfile[line] != NULL)
	{
		colum = 0;
		while (mapcontent->mapfile[line][colum] != '\0')
		{
			if (mapcontent->mapfile[line][colum] == 'P')
				mlx_image_to_window (gamecontent->mlx_ptr,
					gamecontent->image_player,
					(mapcontent->player_colum * WIDTH),
					(mapcontent->player_line * HEIGHT));
			colum++;
		}
		line++;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*gamecontent;

	gamecontent = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		close_hook(gamecontent);
		mlx_terminate(gamecontent->mlx_ptr);
		exit (EXIT_SUCCESS);
	}
	move_with_char(keydata, gamecontent);
	move_with_arrow(keydata, gamecontent);
	take_collectables(gamecontent, gamecontent->mapstruct);
	if (reach_exit(gamecontent, gamecontent->mapstruct) == 0)
	{
		close_hook(gamecontent);
		mlx_terminate(gamecontent->mlx_ptr);
		exit (EXIT_SUCCESS);
	}
}

int	game_on(t_game *gamecontent, t_maps *mapcontent)
{

	gamecontent->col = 0;
	while (mapcontent->mapfile[gamecontent->col] != NULL)
		gamecontent->col++;
	gamecontent->mlx_ptr = mlx_init(ft_strlen(mapcontent->mapfile[0]) * WIDTH,
			gamecontent->col * HEIGHT, "TITO'S LIFE", true);
	gamecontent->texture_player_icon = mlx_load_png("./textures/p_icon.png");
	mlx_set_icon(gamecontent->mlx_ptr, gamecontent->texture_player_icon);
	put_png_to_tex(gamecontent);
	put_tex_to_ima(gamecontent);
	put_right_size(gamecontent, mapcontent);
	put_ima_to_win(gamecontent, mapcontent);
	put_player(gamecontent, mapcontent);
	mlx_key_hook(gamecontent->mlx_ptr, my_keyhook, gamecontent);
	mlx_loop(gamecontent->mlx_ptr);
	close_hook(gamecontent);
	mlx_delete_texture(gamecontent->texture_player_icon);
	mlx_terminate(gamecontent->mlx_ptr);
	return (EXIT_SUCCESS);
}
