/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:40:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/08 11:37:18 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	check_case(char c, int x, int y, t_cnt *content)
{
	if (c == 'P' && !content->isplayer)
	{
		content->player.y = y;
		content->player.x = x;
		content->isplayer++;
	}
	else if (c == 'P' && content->isplayer)
		return (MAP_WRONG);
	else if (c == 'C')
		content->collectible++;
	else if (c == 'E')
		content->exit++;
	else if (c != '1' && c != '0')
		return (MAP_WRONG);
	return (MAP_OKAY);
}

static int	filling(int x, int y, char **draftmap, t_cnt *content)
{
	static int	collectibles = 0;
	static int	exit = 0;

	if (x < 0 || y < 0 || x >= content->size.x || y >= content->size.y)
		return (0);
	if (draftmap[y][x] == 'F' || draftmap[y][x] == '1')
		return (0);
	else if (draftmap[y][x] == 'C')
		collectibles++;
	else if (draftmap[y][x] == 'E')
		exit++;
	draftmap[y][x] = 'F';
	filling(x - 1, y, draftmap, content);
	filling(x + 1, y, draftmap, content);
	filling(x, y - 1, draftmap, content);
	filling(x, y + 1, draftmap, content);
	if (collectibles != content->collectible || !exit)
		return (MAP_WRONG);
	return (MAP_OKAY);
}

static int	flood_fill(t_cnt *content, char **draftmap)
{
	int	res;

	res = filling(content->player.x, content->player.y, draftmap, content);
	ft_freetab(draftmap);
	return (res);
}

void	check_content(char **map, t_cnt *content)
{
	int	i;
	int	k;

	i = 0;
	while (map && map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (!check_case(map[i][k], k, i, content))
				ft_error(map, ERR_CASE);
			k++;
		}
		i++;
	}
	if (!content->collectible || !content->exit || content->exit > 1 || !content->isplayer)
		ft_error(map, ERR_ELEMENTS);
	else if (!flood_fill(content, ft_mapdup(map)))
		ft_error(map, ERR_IMPOSSIBLE);
}

void	check_edges(char **map, t_cnt *content)
{
	int	i;

	i = 0;
	while (i < content->size.x)
	{
		if (map[0][i] != '1' || map[content->size.y - 1][i] != '1')
			ft_error(map, ERR_WALLS);
		i++;
	}
	i = 0;
	while (i < content->size.y)
	{
		if (map[i][0] != '1' || map[i][content->size.x - 1] != '1')
			ft_error(map, ERR_WALLS);
		i++;
	}
}
