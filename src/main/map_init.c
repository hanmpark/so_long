/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:13:11 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/05 21:13:54 by hanmpark         ###   ########.fr       */
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

static int	map_format(char **map, t_parse *mapi)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!*map)
		return (FALSE);
	mapi->size.x = ft_strlen(map[i]) - 1;
	while (map && map[i])
	{
		tmp = ft_substr(map[i], 0, (int)mapi->size.x);
		tmp[mapi->size.x] = 0;
		free(map[i]);
		map[i] = tmp;
		if ((int)ft_strlen(map[i]) != mapi->size.x)
			return (FALSE);
		i++;
	}
	if (!check_edges(map, mapi) || !check_content(map, mapi))
		return (FALSE);
	return (TRUE);
}

char	**map_init(const char *file, t_parse *mapi)
{
	char	**map;
	char	*tmp;
	int		fd;

	mapi_init(mapi);
	mapi->size.y = ft_filelen(file);
	map = malloc((mapi->size.y + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		*map++ = tmp;
		tmp = get_next_line(fd);
	}
	close(fd);
	*map = 0;
	map -= mapi->size.y;
	if (!map_format(map, mapi))
	{
		ft_freetab(map);
		return (NULL);
	}
	return (map);
}
