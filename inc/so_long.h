/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:44 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/15 14:02:47 by hanmpark         ###   ########.fr       */
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
	void	*img_floor[3];
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit[2];
	void	*img_mob;
	char	*floor[3];
	char	*wall;
	char	*collectible;
	char	*exit[2];
	char	*mob;
	int		height;
	int		width;
}				t_img;

typedef struct	s_content
{
	int		isplayer;
	int		collectible;
	int		exit;
}				t_cnt;

typedef struct	s_dir
{
	int	left;
	int	right;
	int	down;
	int	up;
}				t_dir;

typedef struct	s_data
{
	char	**map;
	t_cnt	map_content;
	t_cnt	check;
	t_pos	size;
	t_pos	player;
	void	*mlx;
	void	*win;
	t_img	img;
	int		f_rate;
	t_dir	dir;
}				t_data;

void	map_init(const char *file, t_data *game);
void	check_edges(char **map, t_data *game);
void	check_content(char **map, t_data *game);

void	game_init(t_data *game);
t_cnt	content_init(void);
void	assign_texture(t_data *game);
t_list	*load_dir(char *path, t_data *game);

int		ft_close(t_data *game);
int		key_hook(t_data *game);

int		render(t_pos player, t_data *game);
void	print_img(t_data *game, void *img, int x, int y);

int	update(t_data *game);

#endif