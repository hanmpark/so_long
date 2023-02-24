/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:44 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 18:35:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# include "../src/libft/inc/libft.h"
# include <mlx.h>

# define ERR_MLX "Error\nMLX problem\n"

# define GREEN "\033[32m"
# define RED "\033[31m"
# define DEF "\033[0m"

# define GAME_ON 0
# define GAME_OVER 1
# define GAME_SUCCESS 2

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_img
{
	t_list	*left;
	t_list	*right;
	t_list	*down;
	t_list	*up;
	t_list	*current;
	t_list	*current_back;
	t_list	*mob;
	t_list	*mob_back;
	t_list	*collectible;
	t_list	*collectible_back;
	void	*dead;
	void	*current_exit;
	void	*floor[3];
	void	*exit[2];
	void	*number[10];
	void	*wall;
	void	*border[3];
	int		height;
	int		width;
}				t_img;

typedef struct	s_content
{
	int		isplayer;
	int		collectible;
	int		exit;
	t_pos	exit_pos;
	int		enemy;
}				t_cnt;

typedef struct	s_dir
{
	int	left;
	int	right;
	int	down;
	int	up;
}				t_dir;

typedef struct	s_hook
{
	t_dir	dir;
	t_dir	anim;
	int		is_anim;
}				t_hook;

typedef struct	s_enemy
{
	t_pos	pos;
	int		move_px;
	int		dir;
}				t_enemy;

typedef struct	s_data
{
	char	**map;
	t_cnt	map_content;
	t_pos	size;
	t_pos	player;
	t_pos	move_pl_px;
	int		exit;
	int		count_moves;
	void	*mlx;
	void	*win;
	t_img	img;
	t_hook	hook;
	t_enemy	*enemy;
	int		game_state;
	int		move_enemy;
	int		frames;
}				t_data;

void	game_init(t_data *game);
void	data_init(t_data *game);
void	assign_texture(t_data *game);

int		render(t_data *game);
void	print_img(t_data *game, void *img, int x, int y);
void	print_img_mob(t_data *g, int enemy_number);

int		update(t_data *game);
int		check_path(t_data *game, int x, int y);
void	check_game(t_data *game, t_pos pl, t_enemy *mob);

void	clear_img(t_data *g);

#endif