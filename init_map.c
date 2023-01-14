/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:57:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/14 14:37:33 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static char	*trimnl(char *str)
{
	char	*res;

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
	if (!fd)
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

char	**init_map(const char *file)
{
	char			**map;
	unsigned int	size;
	unsigned int	i;
	int				fd;

	size = map_size(file);
	if (!size)
		return (NULL);
	map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (!fd || fd < 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i] = get_next_line(fd);
		map[i] = trimnl(map[i]);
		if (!map[i])
			break ;
		i++;
	}
	return (map);
}
