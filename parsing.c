/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/14 15:07:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	check_edges(const char **map, int row, int col)
{
	int	i;

	i = 0;
	while (i <= row)
	{
		if (map[0][i] != '1' || map[col][i] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i <= col)
	{
		if (map[i][0] != '1' || map[i][row] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_content(const char **map, t_parse *mapinfo)
{
	int	i;
	int	k;

	return (TRUE);
}

static int	check_format(const char **map, t_parse *mapinfo)
{
	/* the following condition tells wether the map is rectangular or not
	** and wether it has the correct size or not
	*/
	if ((mapinfo->size->x * mapinfo->size->y) < 15)
		return (FALSE);
	if (!check_edges(map, mapinfo->size->x - 1, mapinfo->size->y - 1))
		return (FALSE);
}

static int	count_y(const char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

int	check_map(const char **map, t_parse *mapinfo)
{
	if (!map)
		return (FALSE);
	mapinfo->size->x = (int)ft_strlen(*map);
	mapinfo->size->y = count_y(map);
	if (!check_format(map, mapinfo))
		return (FALSE);
	return (TRUE);
}