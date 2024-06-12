/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:43:02 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/11 13:03:58 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_line(t_maps *mapcontent, char movement)
{
	if (movement == '+' && mapcontent->mapfile[mapcontent->player_line + 1]
		[mapcontent->player_colum] != '1')
	{
		mapcontent->player_line++;
		mapcontent->movements_count++;
		ft_printf("Steps:%d\n", mapcontent->movements_count);
		return (1);
	}
	else if (movement == '-' && mapcontent->mapfile[mapcontent->player_line - 1]
		[mapcontent->player_colum] != '1')
	{
		mapcontent->player_line--;
		mapcontent->movements_count++;
		ft_printf("Steps:%d\n", mapcontent->movements_count);
		return (1);
	}
	else
		return (0);
}

int	move_colum(t_maps *mapcontent, char movement)
{
	if (movement == '+' && mapcontent->mapfile[mapcontent->player_line]
		[mapcontent->player_colum +1] != '1')
	{
		mapcontent->player_colum++;
		mapcontent->movements_count++;
		ft_printf("Steps:%d\n", mapcontent->movements_count);
		return (1);
	}
	else if (movement == '-' && mapcontent->mapfile[mapcontent->player_line]
		[mapcontent->player_colum - 1] != '1')
	{
		mapcontent->player_colum--;
		mapcontent->movements_count++;
		ft_printf("Steps:%d\n", mapcontent->movements_count);
		return (1);
	}
	else
		return (0);
}

int	check_movement(t_maps *mapcontent, char position, char movement)
{
	int	result;

	result = 0;
	if (position == 'x')
		result = move_colum(mapcontent, movement);
	else if (position == 'y')
		result = move_line(mapcontent, movement);
	return (result);
}

void	move_with_char(mlx_key_data_t keydata, t_game	*gamecontent)
{
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		&& (check_movement (gamecontent->mapstruct, 'y', '-') == 1))
			gamecontent->image_player->instances[0].y -= 64;
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		&& (check_movement(gamecontent->mapstruct, 'y', '+') == 1))
			gamecontent->image_player->instances[0].y += 64;
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		&& (check_movement(gamecontent->mapstruct, 'x', '-') == 1))
			gamecontent->image_player->instances[0].x -= 64;
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		&& (check_movement(gamecontent->mapstruct, 'x', '+') == 1))
			gamecontent->image_player->instances[0].x += 64;
}

void	move_with_arrow(mlx_key_data_t keydata, t_game	*gamecontent)
{
	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		&& (check_movement (gamecontent->mapstruct, 'y', '-') == 1))
			gamecontent->image_player->instances[0].y -= 64;
	if ((keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		&& (check_movement(gamecontent->mapstruct, 'y', '+') == 1))
			gamecontent->image_player->instances[0].y += 64;
	if ((keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		&& (check_movement(gamecontent->mapstruct, 'x', '-') == 1))
			gamecontent->image_player->instances[0].x -= 64;
	if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		&& (check_movement(gamecontent->mapstruct, 'x', '+') == 1))
			gamecontent->image_player->instances[0].x += 64;
}
