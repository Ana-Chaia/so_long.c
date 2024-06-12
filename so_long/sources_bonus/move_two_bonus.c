/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_two_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:16:07 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/15 19:04:51 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	mlx_delete_image(gamecontent->mlx_ptr, gamecontent->image_villain);
	mlx_delete_texture(gamecontent->texture_villain);
	mlx_delete_image(gamecontent->mlx_ptr, gamecontent->image_stepsign);
	mlx_delete_texture(gamecontent->texture_stepsign);
	mlx_delete_image(gamecontent->mlx_ptr, gamecontent->image_stepnum);
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

int	meet_villain(t_game *gamecontent)
{
	int	i;

	i = 0;
	while (i < gamecontent->villain_count)
	{
		if (gamecontent->image_villain->instances[i].x
			== (gamecontent->image_player->instances->x)
			&& gamecontent->image_villain->instances[i].y
			== (gamecontent->image_player->instances->y))
		{
			ft_printf("%s\n", "SORRY, COMB TIME!!");
			return (0);
		}
		i++;
	}
	return (1);
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

void	put_sign(t_game *gamecontent, t_maps *mapcontent)
{
	char	*str;

	str = ft_itoa(mapcontent->movements_count);
	mlx_image_to_window(gamecontent->mlx_ptr, gamecontent->image_stepsign, -3,
		-15);
	mlx_resize_image(gamecontent->image_stepsign, 90, 90);
	gamecontent->image_stepnum = mlx_put_string(gamecontent->mlx_ptr, str, 25,
			15);
	mlx_resize_image(gamecontent->image_stepnum, 30, 30);
	free(str);
}
