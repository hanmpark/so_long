/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:13:11 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/14 09:15:10 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	map_format(char **map, t_data *game)
{
	char	*tmp;
	int		i;

	i = 0;
	game->size.x = (int)ft_strlen(map[i]) - 1;
	while (map && map[i])
	{
		tmp = ft_strtrim(map[i], "\n");
		free(map[i]);
		map[i] = tmp;
		if ((int)ft_strlen(map[i]) != game->size.x)
			ft_error(map, ERR_FORMAT);
		i++;
	}
	check_edges(map, game);
	check_content(map, game);
}

static void	map_set(const char *file, t_data *game)
{
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		game->map[i++] = tmp;
		tmp = get_next_line(fd);
	}
	close(fd);
	game->map[i] = 0;
	if (!*game->map)
		ft_error(game->map, ERR_BER);
}

void	map_init(const char *file, t_data *game)
{
	game->map_content = content_init();
	game->size.y = ft_filelen(file);
	game->map = malloc((game->size.y + 1) * sizeof(char *));
	if (!game->map)
		ft_error(game->map, ERR_MALLOC);
	map_set(file, game);
	map_format(game->map, game);
}
