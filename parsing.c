/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/14 20:23:16 by hanmpark         ###   ########.fr       */
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

static int	check_format(const char **map, t_parse *mapinfo)
{
	int	i;
	int	len;

	i = 0;
	mapinfo->size.x = (int)ft_strlen(*map);
	if (mapinfo->size.x == mapinfo->size.y)
		return (FALSE);
	if (((mapinfo->size.x * mapinfo->size.y) < 15) && mapinfo->size.x > 2
		&& mapinfo->size.y > 2)
		return (FALSE);
	len = (int)ft_strlen(map[i]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (FALSE);
		i++;
	}
	if (!check_edges(map, mapinfo->size.x - 1, mapinfo->size.y - 1))
		return (FALSE);
	return (TRUE);
}

int	check_map(const char **map, t_parse *mapinfo)
{
	if (!map)
		return (FALSE);
	if (!check_format(map, mapinfo))
		return (FALSE);
	return (TRUE);
}
