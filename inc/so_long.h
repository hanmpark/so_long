/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:44 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/06 12:55:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../src/libft/includes/ft_printf.h"
# include "../src/libft/includes/get_next_line.h"
# include <mlx.h>

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
void	check_edges(char **map, t_parse *mapi);
void	check_content(char **map, t_parse *mapi);

#endif