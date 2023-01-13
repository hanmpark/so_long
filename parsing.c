/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/14 00:16:45 by hanmpark         ###   ########.fr       */
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
	int				fd;
	int				i;

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

static int	check_edges(const char **map, int row_len, int col_len)
{
	int	i;

	i = 0;
	while (i <= row_len)
	{
		if ((map[0][i] != '1') || (map[col_len][i] != '1'))
			return (FALSE);
		i++;
	}
	i = 0;
	while (i <= col_len)
	{
		if (map[i][0] != '1' || map[i][row_len] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_len(const char **map, int line_len)
{
	int	count;

	count = 0;
	while (map[count] && (int)ft_strlen(map[count]) == line_len)
		count++;
	if (map[count])
		return (FALSE);
	return (count);
}

int	check_map(const char **map)
{
	int	x_len;
	int	y_len;

	if (!map)
		return (FALSE);
	x_len = (int)ft_strlen(*map);
	y_len = check_len(map, x_len);
	if (!y_len)
		return (FALSE);
	if (!check_edges(map, x_len - 1, y_len - 1))
		return (FALSE);
	return (TRUE);
}