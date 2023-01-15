/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:57:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/15 17:37:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static char	*trimnl(char *str)
{
	char	*res;

	if (!str)
		return (NULL);
	res = ft_strtrim(str, "\n");
	free(str);
	return (res);
}

static int	map_size(const char *file)
{
	char	*str;
	int		fd;
	int		size;

	fd = open(file, O_RDONLY);
	if (!fd || fd < 0)
		return (0);
	size = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		size++;
		free(str);
	}
	close(fd);
	return (size);
}

static int	get_content(char *line, t_parse *mapinfo, int y_pos)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == 'P')
		{
			mapinfo->player.x = i;
			mapinfo->player.y = y_pos;
		}
		else if (line[i] == 'C')
			mapinfo->collectible++;
		else if (line[i] == 'E')
			mapinfo->exit++;
		else if (line[i] != '0')
			return (FALSE);
		i++;
	}
	if (!mapinfo->collectible || !mapinfo->exit || (!mapinfo->player.x && !mapinfo->player.y))
		return (FALSE);
	return (TRUE);
}

static int	build_map(t_parse *mapinfo, char **map, const char *file)
{
	int	i;
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd || fd < 0)
		return (NULL);
	i = 0;
	while (i < mapinfo->size.y)
	{
		map[i] = get_next_line(fd);
		map[i] = trimnl(map[i]);
		if (!map[i])
			break ;
		if (!get_content(map[i], mapinfo, i))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	**init_map(const char *file, t_parse *mapinfo)
{
	char	**map;
	int		i;
	int		fd;
	
	ft_memset(mapinfo, 0, sizeof(t_parse));
	mapinfo->size.y = map_size(file);
	if (!mapinfo->size.y)
		return (NULL);
	map = ft_calloc(mapinfo->size.y + 1, sizeof(char *));
	if (!map)
		return (NULL);
	return (map);
}
