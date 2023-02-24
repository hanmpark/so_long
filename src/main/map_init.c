/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:13:11 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 07:41:31 by hanmpark         ###   ########.fr       */
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

static t_enemy	enemy_data_set(int x, int y, t_data *game)
{
	t_enemy	en;

	en.pos.x = x;
	en.pos.y = y;
	en.move_px = 0;
	if (ft_check_path(x - 1, y, 1, game))
		en.dir = LEFT;
	else if (ft_check_path(x + 1, y, 1, game))
		en.dir = RIGHT;
	else
		en.dir = STATIC;
	return (en);
}

static void	enemy_set(t_data *game)
{
	int	index;
	int	y;
	int	x;

	game->enemy = malloc((game->map_content.enemy) * sizeof(t_enemy));
	if (!game->enemy)
		ft_error(game->map, ERR_MALLOC);
	index = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'M')
			{
				game->enemy[index] = enemy_data_set(x, y, game);
				index++;
			}
		}
	}
}

void	map_init(const char *file, t_data *game)
{
	int	len;

	len = ft_strlen(file) - 4;
	if (ft_strncmp(file + len, ".ber", 4) != 0)
		ft_error (game->map, ERR_BER);
	game->map_content = content_init();
	game->size.y = ft_filelen(file);
	game->map = malloc((game->size.y + 1) * sizeof(char *));
	if (!game->map)
		ft_error(game->map, ERR_MALLOC);
	map_set(file, game);
	map_format(game->map, game);
	enemy_set(game);
}
