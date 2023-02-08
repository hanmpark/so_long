/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:13:11 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/08 11:37:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	map_format(char **map, t_cnt *content)
{
	char	*tmp;
	int		i;

	i = 0;
	content->size.x = (int)ft_strlen(map[i]) - 1;
	ft_printf("\033[32mMAP\033[0m\n");
	while (map && map[i])
	{
		tmp = ft_strtrim(map[i], "\n");
		free(map[i]);
		map[i] = tmp;
		ft_printf("\033[32m%s\033[0m\n", map[i]);
		if ((int)ft_strlen(map[i]) != content->size.x)
			ft_error(map, ERR_FORMAT);
		i++;
	}
	check_edges(map, content);
	check_content(map, content);
}

static void	map_set(const char *file, char **map)
{
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		map[i++] = tmp;
		tmp = get_next_line(fd);
	}
	map[i] = 0;
	close(fd);
}

char	**map_init(const char *file, t_cnt *content)
{
	char	**map;

	content_init(content);
	content->size.y = ft_filelen(file);
	map = malloc((content->size.y) * sizeof(char *));
	if (!map)
		ft_error(map, ERR_MALLOC);
	map_set(file, map);
	map_format(map, content);
	return (map);
}
