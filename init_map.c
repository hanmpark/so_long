/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:13:11 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/23 00:02:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	map_format(char **map, t_parse *mapi)
{
	int	times;
	int	linelen;
	int	i;

	i = 0;
	times = mapi->size.y;
	while (times--)
	{
		if (ft_strlen(map[i]) != linelen)
			return (ft_freetabarray(map));
	}
}

char	**map_init(const char *file, t_parse *mapi)
{
	char	**map;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	mapi->size.y = 0;
	while (tmp)
	{
		map[mapi->size.y] = tmp;
		free(tmp);
		tmp = get_next_line(fd);
		mapi->size.y++;
	}
	if (!map)
		return (NULL);
	return (map)
}