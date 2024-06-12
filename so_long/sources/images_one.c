/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:12:45 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/16 12:57:16 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(void)
{
	puts (mlx_strerror(mlx_errno));
	exit (EXIT_FAILURE);
}

void	put_png_to_tex(t_game *gamecontent)
{
	gamecontent->texture_wallpaper = mlx_load_png("./textures/wallpaper.png");
	if (!gamecontent->texture_wallpaper)
		print_error();
	gamecontent->texture_wall = mlx_load_png("./textures/wall.png");
	if (!gamecontent->texture_wall)
		print_error();
	gamecontent->texture_collectible = mlx_load_png("./textures/collect.png");
	if (!gamecontent->texture_collectible)
		print_error();
	gamecontent->texture_exit = mlx_load_png("./textures/exit.png");
	if (!gamecontent->texture_exit)
		print_error();
	gamecontent->texture_player = mlx_load_png("./textures/player.png");
	if (!gamecontent->texture_player)
		print_error();
}

void	put_tex_to_ima(t_game *gamecontent)
{
	gamecontent->image_wallpaper = mlx_texture_to_image(gamecontent->mlx_ptr,
			gamecontent->texture_wallpaper);
	if (!gamecontent->image_wallpaper)
		print_error();
	gamecontent->image_wall = mlx_texture_to_image(gamecontent->mlx_ptr,
			gamecontent->texture_wall);
	if (!gamecontent->image_wall)
		print_error();
	gamecontent->image_collectible = mlx_texture_to_image(gamecontent->mlx_ptr,
			gamecontent->texture_collectible);
	if (!gamecontent->image_collectible)
		print_error();
	gamecontent->image_exit = mlx_texture_to_image(gamecontent->mlx_ptr,
			gamecontent->texture_exit);
	gamecontent->image_exit->enabled = 0;
	if (!gamecontent->image_exit)
		print_error();
	gamecontent->image_player = mlx_texture_to_image(gamecontent->mlx_ptr,
			gamecontent->texture_player);
	if (!gamecontent->image_player)
		print_error();
}

void	put_right_size(t_game *gamecontent, t_maps *mapcontent)
{
	mlx_resize_image(gamecontent->image_wallpaper, ft_strlen
		(mapcontent->mapfile[0]) * WIDTH, gamecontent->col * HEIGHT);
	mlx_resize_image(gamecontent->image_wall, WIDTH, HEIGHT);
	mlx_resize_image(gamecontent->image_collectible, WIDTH, HEIGHT);
	mlx_resize_image(gamecontent->image_exit, WIDTH, HEIGHT);
	mlx_resize_image(gamecontent->image_player, WIDTH, HEIGHT);
}

void	put_each_image(t_game *gamecontent, char position, int x, int y)
{
	if (!x && !y)
		mlx_image_to_window (gamecontent->mlx_ptr, gamecontent->image_wallpaper,
			0, 0);
	if (position == '1')
		mlx_image_to_window (gamecontent->mlx_ptr, gamecontent->image_wall, x,
			y);
	else if (position == 'C')
		mlx_image_to_window (gamecontent->mlx_ptr,
			gamecontent->image_collectible, x, y);
	else if (position == 'E')
		mlx_image_to_window (gamecontent->mlx_ptr, gamecontent->image_exit, x,
			y);
}
