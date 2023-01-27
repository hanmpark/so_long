/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:44 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/27 17:44:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
//# include <mlx.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct	s_parse
{
	t_pos	player;
	int		isplayer;
	int		collectible;
	int		exit;
	t_pos	size;
}	t_parse;

char	**map_init(const char *file, t_parse *mapi);
int		check_edges(char **map, t_parse *mapi);
int		check_content(char **map, t_parse *mapi);

#endif