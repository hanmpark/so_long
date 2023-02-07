/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:44 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/07 16:22:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "parsing.h"
# include <mlx.h>

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

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
	t_vector	size;
}				t_win;

typedef struct	s_img
{
	void	*id;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
	t_vector	size;
}				t_img;

typedef struct	s_data
{
	void	*mlx;
	t_win	win;
	t_img	sprite;
	t_vector	sprite_pos;
}				t_data;

void	game_init(char **map, t_parse *mapi);

#endif