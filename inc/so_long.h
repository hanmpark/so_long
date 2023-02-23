/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:44 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/23 19:46:11 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/libft/includes/get_next_line.h"
# include "../src/libft/includes/ft_printf.h"
# include <mlx.h>

# define MAP_OKAY 1
# define MAP_WRONG 0

/* ***************************** Error messages ***************************** */
# define ERR_MALLOC "Error\nMalloc failed\n"
# define ERR_FORMAT "Error\nFormat error\n"
# define ERR_WALLS "Error\nFound an element different from '1' for wall(s)\n"
# define ERR_ELEMENTS "Error\nWrong number of elements\n"
# define ERR_IMPOSSIBLE "Error\nYour map is impossible !\n"
# define ERR_CASE "Error\nSomething wrong with case(s)\n"
# define ERR_BER "Error\n.ber file does not exist\n"
# define ERR_MLX "Error\nMLX problem\n"

/* ******************************* Key events ******************************* */
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEY_ESC 53
# define KEY_L 0
# define KEY_D 1
# define KEY_R 2
# define KEY_U 13

/* ENEMY MOVEMENT */
# define LEFT 1
# define RIGHT 2
# define STATIC 0

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
	t_list	*down;
	t_list	*left;
	t_list	*right;
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

/* map functions */
void	map_init(const char *file, t_data *game);
void	check_edges(char **map, t_data *game);
void	check_content(char **map, t_data *game);

/* game_init */
void	game_init(t_data *game);
t_cnt	content_init(void);
void	assign_texture(t_data *game);

int		ft_close(t_data *game);
void	move_dir(int x, int y, t_data *game);

int		render(t_data *game);
void	print_img(t_data *game, void *img, int x, int y);
void	print_img_mob(t_data *g, int enemy_number);

int		key_released(int key, t_data *game);
int		key_pressed(int key, t_data *game);

int		update(t_data *game);
int		ft_check_path(int x, int y, int enemy, t_data *game);
void	check_game(t_pos pl, t_enemy *mob, t_data *game);

void	move_player(t_data *game);
void	move_enemy(t_data *game);

#endif