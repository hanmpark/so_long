/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:13:11 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/06 16:01:23 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	mapi_init(t_parse *mapi)
{
	mapi->isplayer = 0;
	mapi->collectible = 0;
	mapi->exit = 0;
	mapi->player.x = 0;
	mapi->player.y = 0;
	mapi->size.x = 0;
	mapi->size.y = 0;
}

static void	map_format(char **map, t_parse *mapi)
{
	char	*tmp;
	int		i;

	i = 0;
	mapi->size.x = (int)ft_strlen(map[i]) - 1;
	ft_printf("\033[32mMAP\033[0m\n");
	while (map && map[i])
	{
		tmp = ft_strtrim(map[i], "\n");
		free(map[i]);
		map[i] = tmp;
		ft_printf("\033[32m%s\033[0m\n", map[i]);
		if ((int)ft_strlen(map[i]) != mapi->size.x)
			ft_maperror(map, mapi, "Format error");
		i++;
	}
	check_edges(map, mapi);
	check_content(map, mapi);
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

char	**map_init(const char *file, t_parse *mapi)
{
	char	**map;

	mapi_init(mapi);
	mapi->size.y = ft_filelen(file);
	map = malloc((mapi->size.y + 1) * sizeof(char *));
	if (!map)
		ft_maperror(map, mapi, "Malloc failed");
	map_set(file, map);
	map_format(map, mapi);
	return (map);
}
