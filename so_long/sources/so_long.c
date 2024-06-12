/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:08:47 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/15 20:15:54 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_maps	mapcontent;
	t_game	gamecontent;

	if (argc != 2)
		ft_printf("ERROR - nbr of arguments \n");
	else
	{
		if (ft_file_validation(argv, &mapcontent) == 0)
			return (0);
		gamecontent.mapstruct = &mapcontent;
		mapcontent.mapfile = ft_split(mapcontent.filecontent, '\n');
		free (mapcontent.filecontent);
		if (mapcontent.mapfile == NULL)
			return (0);
		if (is_map_valid (&mapcontent) == 0)
			return (0);
		mapcontent.movements_count = 0;
		ft_printf("Steps:%d\n", mapcontent.movements_count);
		if (game_on(&gamecontent, &mapcontent) == 0)
			return (0);
	}
	return (0);
}
