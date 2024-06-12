/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:43:10 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/25 19:17:54 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define WIDTH 64
# define HEIGHT 64

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libplus/libft.h"
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

struct s_mapsvalidation {
	char	**mapfile;
	char	*filecontent;
	int		player_line;
	int		player_colum;
	int		movements_count;
	int		collectibles_count;
	int		collectibles_taken;
	int		player_count;
};

typedef struct s_mapsvalidation	t_maps;

struct s_gaming {
	mlx_t			*mlx_ptr;
	mlx_texture_t	*texture_wallpaper;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_collectible;
	mlx_texture_t	*texture_exit;
	mlx_texture_t	*texture_player;
	mlx_texture_t	*texture_player_icon;
	mlx_texture_t	*texture_stepsign;
	mlx_texture_t	*texture_villain;
	mlx_image_t		*image_wallpaper;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_collectible;
	mlx_image_t		*image_exit;
	mlx_image_t		*image_player;
	mlx_image_t		*image_stepnum;
	mlx_image_t		*image_stepsign;
	mlx_image_t		*image_villain;
	int				villain_count;
	int				col;
	int				line;
	t_maps			*mapstruct;
};

typedef struct s_gaming			t_game;

//file_validation_bonus.c
int		is_extension_valid(char *argv[]);
char	*read_file(int file_descriptor);
char	*open_file(char *filename);
int		is_there_space(char*text);
int		ft_file_validation_bonus(char **argv, t_maps *mapcontent);

// validation_one_bonus.c
int		is_map_rectangular(t_maps *mapcontent);
int		is_there_p(t_maps *mapcontent);
int		is_there_e(t_maps *mapcontent);
int		is_there_c(t_maps *mapcontent);
int		is_there_chr(t_maps *mapcontent, const char *str, char *error_message);

// validation_two_bonus.c
int		is_there_wall(t_maps *mapcontent);
void	flood_fill(t_maps *mapcontent, int row, int col);
int		check_flood(t_maps *mapcontent);
void	free_matrix(t_maps *mapcontent);
int		is_map_valid(t_maps *mapcontent);

// validation_three_bonus.c
void	x_flood_fill(t_maps *mapcontent, int row, int col);

//images_one_bonus.c
void	print_error(void);
void	put_png_to_tex(t_game *gamecontent);
void	put_tex_to_ima(t_game *gamecontent);
void	put_tex_to_ima_bonus(t_game *gamecontent);
void	put_right_size(t_game *gamecontent, t_maps *mapcontent);

// images_two_bonus.c
void	put_each_image(t_game *gamecontent, char position, int x, int y);
void	put_ima_to_win(t_game *gamecontent, t_maps *mapcontent);
void	put_player(t_game *gamecontent, t_maps *mapcontent);
void	my_keyhook(mlx_key_data_t keydata, void *param);
int		game_on(t_game *gamecontent, t_maps *mapcontent);

// move_one_bonus.c

int		move_line(t_maps *mapcontent, char movement);
int		move_colum(t_maps *mapcontent, char movement);
int		check_movement(t_maps *mapcontent, char position, char movement);
void	move_with_char(mlx_key_data_t keydata, t_game	*gamecontent);
void	move_with_arrow(mlx_key_data_t keydata, t_game	*gamecontent);

// move_two_bonus.c

void	close_hook(t_game *gamecontent);
void	take_collectables(t_game *gamecontent, t_maps *mapcontent);
int		reach_exit(t_game *gamecontent, t_maps *mapcontent);
int		meet_villain(t_game *gamecontent);
void	put_sign(t_game *gamecontent, t_maps *mapcontent);

//so_long_utils_bonus.c
void	printmap(char**mapfile);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr_inverse(const char *str, int chr);

// so_long_bonus.c
int		main(int argc, char **argv);

#endif
