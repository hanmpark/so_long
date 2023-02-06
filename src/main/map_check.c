/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:40:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/06 16:27:11 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	check_case(char c, int x, int y, t_parse *mapi)
{
	if (c == 'P' && !mapi->isplayer)
	{
		mapi->player.y = y;
		mapi->player.x = x;
		mapi->isplayer++;
	}
	else if (c == 'P' && mapi->isplayer)
		return (FALSE);
	else if (c == 'C')
		mapi->collectible++;
	else if (c == 'E')
		mapi->exit++;
	else if (c != '1' && c != '0')
		return (FALSE);
	return (TRUE);
}

static int	filling(int x, int y, char **draftmap, t_parse *mapi)
{
	static int	collectibles = 0;
	static int	exit = 0;

	if (x < 0 || y < 0 || x >= mapi->size.x || y >= mapi->size.y)
		return (0);
	if (draftmap[y][x] == 'F' || draftmap[y][x] == '1')
		return (0);
	else if (draftmap[y][x] == 'C')
		collectibles++;
	else if (draftmap[y][x] == 'E')
		exit++;
	draftmap[y][x] = 'F';
	filling(x - 1, y, draftmap, mapi);
	filling(x + 1, y, draftmap, mapi);
	filling(x, y - 1, draftmap, mapi);
	filling(x, y + 1, draftmap, mapi);
	if (collectibles != mapi->collectible || !exit)
		return (0);
	return (1);
}

static int	flood_fill(t_parse *mapi, char **draftmap)
{
	int	res;

	res = filling(mapi->player.x, mapi->player.y, draftmap, mapi);
	ft_freetab(draftmap);
	return (res);
}

void	check_content(char **map, t_parse *mapi)
{
	int	i;
	int	k;

	i = 0;
	while (map && map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (!check_case(map[i][k], k, i, mapi))
				ft_maperror(map, mapi, "Something wrong with case(s)");
			k++;
		}
		i++;
	}
	if (!mapi->collectible || !mapi->exit || mapi->exit > 1 || !mapi->isplayer)
		ft_maperror(map, mapi, "Wrong number of elements in the chosen map");
	else if (!flood_fill(mapi, ft_mapdup(map)))
		ft_maperror(map, mapi, "Your map is impossible");
}

void	check_edges(char **map, t_parse *mapi)
{
	int	i;

	i = 0;
	while (i < mapi->size.x)
	{
		if (map[0][i] != '1' || map[mapi->size.y - 1][i] != '1')
			ft_maperror(map, mapi, "Edges walls problem");
		i++;
	}
	i = 0;
	while (i < mapi->size.y)
	{
		if (map[i][0] != '1' || map[i][mapi->size.x - 1] != '1')
			ft_maperror(map, mapi, "Edges walls problem");
		i++;
	}
}
