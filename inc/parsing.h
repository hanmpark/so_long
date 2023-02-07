/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 07:16:41 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/07 07:47:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../src/libft/includes/get_next_line.h"
# include "../src/libft/includes/ft_printf.h"

# define MAP_OKAY 1
# define MAP_WRONG 0

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