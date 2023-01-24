/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:13:11 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/24 16:28:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	check_edges(char **map, t_parse *mapi)
{
	int	i;

	i = 0;
	printf("pass\n");
	while (i <= mapi->size.x - 1)
	{
		if (map[0][i] != '1' || map[mapi->size.y - 1][i] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i <= mapi->size.y - 1)
	{
		if (map[i][0] != '1' || map[i][mapi->size.x - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_case(char c, int x, int y, t_parse *mapi)
{
	static int	passed;

	passed = 0;
	if (c == 'P' && !passed)
	{
		mapi->player.y = y;
		mapi->player.x = x;
		passed++;
	}
	else if (c == 'P' && passed)
		return (FALSE);
	else if (c == 'C')
		mapi->collectible++;
	else if (c == 'E')
		mapi->exit++;
	else if (c != '1' && c != '0')
		return (FALSE);
	return (TRUE);
}

static int	check_content(char **map, t_parse *mapi)
{
	int	i;
	int	k;

	i = 0;
	while (map && map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (!check_case(map[i][k], k, i, mapi))
				return (FALSE);
			k++;
		}
		i++;
	}
	return (TRUE);
}

static void	map_format(char **map, t_parse *mapi)
{
	char	*tmp;
	int		i;

	i = 0;
	mapi->size.x = ft_strlen(map[i]);
	while (map && map[i])
	{
		if (ft_strlen(map[i]) != mapi->size.x)
			return (ft_freetabarray(map));
		tmp = ft_substr(map[i], 0, (int)mapi->size.x - 1);
		tmp[mapi->size.x - 1] = 0;
		free(map[i]);
		map[i] = tmp;
		i++;
	}
	mapi->collectible = 0;
	mapi->exit = 0;
	if (!check_edges(map, mapi) || !check_content(map, mapi))
		return (ft_freetabarray(map));
}

static int	count_len(const char *file)
{
	char	*tmp;
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	len = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		len++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (len);
}

char	**map_init(const char *file, t_parse *mapi)
{
	char	**map;
	char	*tmp;
	int		fd;

	map = malloc((count_len(file) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	mapi->size.y = 0;
	while (tmp)
	{
		map[mapi->size.y] = tmp;
		tmp = get_next_line(fd);
		mapi->size.y++;
	}
	close(fd);
	map_format(map, mapi);
	return (map);
}
