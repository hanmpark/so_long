/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:44 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/08 19:15:51 by hanmpark         ###   ########.fr       */
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

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	o;
}				t_color;

typedef struct	s_win
{
	void	*id;
	t_pos	size;
}				t_win;

typedef struct	s_img
{
	void	*img_floor;
	void	*img_floor1;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	char	*floor;
	char	*floor1;
	char	*wall;
	char	*collectible;
	char	*exit;
	int		height;
	int		width;
}				t_img;

typedef struct	s_content
{
	t_pos	player;
	int		isplayer;
	int		collectible;
	int		exit;
	t_pos	size;
}				t_cnt;

typedef struct	s_data
{
	char	**map;
	t_cnt	content;
	void	*mlx;
	t_win	win;
	t_img	sprite;
	t_pos	player_pos;
}				t_data;

char	**map_init(const char *file, t_cnt *mapi);
void	check_edges(char **map, t_cnt *mapi);
void	check_content(char **map, t_cnt *mapi);
void	content_init(t_cnt *content);

void	game_init(t_data *game);
void	content_init(t_cnt *content);
void	assign_texture(t_data *game);
int		render(t_data *game);

#endif