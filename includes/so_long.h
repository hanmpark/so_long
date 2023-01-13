/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:44 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/13 23:55:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
//# include <mlx.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_parse
{
	int	player;
	int	collectible;
	int	exit;
}	t_parse;

typedef struct	s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct	s_window
{
	void		*reference;
	t_vector	size;
}	t_window;

typedef struct	s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct	s_program
{
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}	t_program;

char	**init_map(const char *file);
int		check_map(const char **map);

#endif