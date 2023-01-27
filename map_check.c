/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:40:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/27 17:47:20 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

int	check_content(char **map, t_parse *mapi)
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
				return (FALSE);
			k++;
		}
		i++;
	}
	if (!mapi->collectible || !mapi->exit || !mapi->isplayer)
		return (FALSE);
	return (TRUE);
}

int	check_edges(char **map, t_parse *mapi)
{
	int	i;

	i = 0;
	while (i < mapi->size.x)
	{
		if (map[0][i] != '1' || map[mapi->size.y - 1][i] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < mapi->size.y)
	{
		if (map[i][0] != '1' || map[i][mapi->size.x - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
