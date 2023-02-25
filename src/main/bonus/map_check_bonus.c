/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:40:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/25 12:12:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/game_bonus.h"
#include "../../../inc/parsing_bonus.h"

static int	check_case(char c, int x, int y, t_data *game)
{
	if (c == 'P' && !game->map_content.isplayer)
	{
		game->player.x = x;
		game->player.y = y;
		game->map_content.isplayer++;
	}
	else if (c == 'P' && game->map_content.isplayer)
		return (MAP_ERROR);
	else if (c == 'C')
		game->map_content.collectible++;
	else if (c == 'E')
	{
		game->map_content.exit++;
		game->map_content.exit_pos.x = x;
		game->map_content.exit_pos.y = y;
	}
	else if (c == 'M')
		game->map_content.enemy++;
	else if (c != '1' && c != '0')
		return (MAP_ERROR);
	return (MAP_OKAY);
}

static int	filling(int x, int y, char **draftmap, t_data *g)
{
	static int	collectible = 0;
	static int	exit = 0;

	if (x < 0 || y < 0 || x >= g->size.x || y >= g->size.y)
		return (0);
	if (draftmap[y][x] == 'F' || draftmap[y][x] == '1' || \
		draftmap[y][x] == 'M')
		return (0);
	else if (draftmap[y][x] == 'C')
		collectible++;
	else if (draftmap[y][x] == 'E')
		exit++;
	draftmap[y][x] = 'F';
	filling(x - 1, y, draftmap, g);
	filling(x + 1, y, draftmap, g);
	filling(x, y - 1, draftmap, g);
	filling(x, y + 1, draftmap, g);
	if (collectible != g->map_content.collectible || !exit)
		return (MAP_ERROR);
	return (MAP_OKAY);
}

static int	flood_fill(t_data *game, char **tmpmap)
{
	if (!filling(game->player.x, game->player.y, tmpmap, game))
	{
		ft_freetab(tmpmap);
		return (MAP_ERROR);
	}
	ft_freetab(tmpmap);
	return (MAP_OKAY);
}

void	check_content(char **map, t_data *game)
{
	int	i;
	int	k;

	i = 0;
	while (map && map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (!check_case(map[i][k], k, i, game))
				ft_error(map, game->enemy, ERR_CASE);
			k++;
		}
		i++;
	}
	if (!game->map_content.collectible || game->map_content.exit != 1 || \
		game->map_content.isplayer != 1)
		ft_error(map, game->enemy, ERR_ELEMENTS);
	else if (flood_fill(game, ft_mapdup(map)) == MAP_ERROR)
		ft_error(map, game->enemy, ERR_IMPOSSIBLE);
}

void	check_edges(char **map, t_data *game)
{
	int	i;

	i = 0;
	while (i < game->size.x)
	{
		if (map[0][i] != '1' || map[game->size.y - 1][i] != '1')
			ft_error(map, game->enemy, ERR_WALLS);
		i++;
	}
	i = 0;
	while (i < game->size.y)
	{
		if (map[i][0] != '1' || map[i][game->size.x - 1] != '1')
			ft_error(map, game->enemy, ERR_WALLS);
		i++;
	}
}
