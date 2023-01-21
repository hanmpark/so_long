/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/21 00:07:31 by hanmpark         ###   ########.fr       */
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

/*static int	check_content(const char *file, t_parse *mapinfo)
{
	
}*/

int	check_map(const char **map, t_parse *mapinfo)
{
	if (!map)
		return (FALSE);
	if (!check_format(map, mapinfo))
		return (FALSE);
	return (TRUE);
}
