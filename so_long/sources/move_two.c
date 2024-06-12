/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:16:07 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/25 19:11:29 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_hook(t_game *gamecontent)
{
	free_matrix(gamecontent->mapstruct);
	mlx_delete_image(gamecontent->mlx_ptr, gamecontent->image_wallpaper);
	mlx_delete_texture(gamecontent->texture_wallpaper);
	mlx_delete_image(gamecontent->mlx_ptr, gamecontent->image_wall);
	mlx_delete_texture(gamecontent->texture_wall);
	mlx_delete_image(gamecontent->mlx_ptr, gamecontent->image_collectible);
	mlx_delete_texture(gamecontent->texture_collectible);
	mlx_delete_image(gamecontent->mlx_ptr, gamecontent->image_exit);
	mlx_delete_texture(gamecontent->texture_exit);
	mlx_delete_image(gamecontent->mlx_ptr, gamecontent->image_player);
	mlx_delete_texture(gamecontent->texture_player);
	mlx_close_window(gamecontent->mlx_ptr);

}

void	take_collectables(t_game *gamecontent, t_maps *mapcontent)
{
	int	i;

	i = 0;
	while (i < mapcontent->collectibles_count)
	{
		if ((gamecontent->image_collectible->instances[i].x
				== (gamecontent->image_player->instances->x)
				&& gamecontent->image_collectible->instances[i].y
				== (gamecontent->image_player->instances->y))
			&& gamecontent->image_collectible->instances[i].enabled)
		{
				gamecontent->image_collectible->instances[i].enabled = false;
				mapcontent->collectibles_taken--;
		}
		i++;
	}
}

int	reach_exit(t_game *gamecontent, t_maps *mapcontent)
{
	if (mapcontent->collectibles_taken == 0)
		gamecontent->image_exit->enabled = 1;
	if ((gamecontent->image_player->instances->x
			== gamecontent->image_exit->instances->x)
		&& (gamecontent->image_player->instances->y
			== gamecontent->image_exit->instances->y)
		&& (gamecontent->image_exit->enabled == 1))
	{
		ft_printf("%s", "YOU WIN!!");
		return (0);
	}
	else
		return (1);
}
