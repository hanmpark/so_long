/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/14 23:04:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	set_dir_player(t_data *game)
{
	if (game->dir.left)
		game->img.current = game->img.left;
	else if (game->dir.right)
		game->img.current = game->img.right;
	else if (game->dir.down)
		game->img.current = game->img.down;
	else if (game->dir.up)
		game->img.current = game->img.up;
	game->img.current_back = game->img.current;
}

static int	ft_check_path(int x, int y, t_data *game)
{
	set_dir_player(game);
	if (game->map[y][x] == 'C')
	{
		game->check.collectible++;
		game->map[y][x] = '0';
		if (game->check.collectible == game->map_content.collectible)
			game->check.exit++;
		return (1);
	}
	else if ((game->map[y][x] != '1' && game->map[y][x] != 'E') || \
		(game->map[y][x] == 'E' && game->check.exit))
		return (1);
	return (0);
}

static void	move_dir(int x, int y, t_data *game)
{
	if (game->map[y][x] == 'E')
		ft_close(game);
	else
		game->map[game->player.y][game->player.x] = '0';
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
}

int	key_hook(t_data *game)
{
	t_pos	pos;

	pos = game->player;
	if (game->dir.left && ft_check_path(pos.x - 1, pos.y, game) && game->f_rate % 50)
		move_dir(pos.x - 1, pos.y, game);
	else if (game->dir.right && ft_check_path(pos.x + 1, pos.y, game) && game->f_rate % 50)
		move_dir(pos.x + 1, pos.y, game);
	else if (game->dir.down && ft_check_path(pos.x, pos.y + 1, game) && game->f_rate % 50)
		move_dir(pos.x, pos.y + 1, game);
	else if (game->dir.up && ft_check_path(pos.x, pos.y - 1, game) && game->f_rate % 50)
		move_dir(pos.x, pos.y - 1, game);
	return (0);
}
