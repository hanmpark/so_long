/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:05:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/09/14 00:58:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../../libft/inc/libft.h"
# include "../../libft/inc/ft_printf.h"
# include "../../minilibx-mac/mlx.h"

# define ERR_MLX "Error\nMLX problem\n"

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEY_ESC 53
# define KEY_L 0
# define KEY_D 1
# define KEY_R 2
# define KEY_U 13
# define KEY_SPACE 49

# define GREEN "\033[32m"
# define RED "\033[31m"
# define DEF "\033[0m"

# define GAME_ON 0
# define GAME_OVER 1
# define GAME_SUCCESS 2

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	void	*player;
	void	*collectible;
	void	*floor;
	void	*exit;
	void	*wall;
	int		height;
	int		width;
}	t_img;

typedef struct s_cnt
{
	int		isplayer;
	int		collectible;
	int		exit;
	t_pos	exit_pos;
}	t_cnt;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	t_cnt	map_content;
	t_pos	size;
	t_pos	player;
	t_img	img;
	int		exit;
	int		count_moves;
}	t_data;

void	game_init(t_data *game);
int		check_path(t_data *game, int x, int y);
void	move_player(t_data *game, int x, int y);

int		key_pressed(int key, t_data *game);
int		game_close(t_data *game);
void	print_img(t_data *game, void *img, int x, int y);

void	render(t_data *game, char **map);

#endif