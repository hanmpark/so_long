/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/13 13:40:10 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	ft_check_path(int x, int y, t_data *game)
{
	if (game->map[y][x] == 'C')
	{
		game->check.collectible++;
		game->map[y][x] = '0';
		if (!game->check.exit && game->check.collectible == game->content.collectible)
			game->check.exit++;
		return (1);
	}
	else if ((game->map[y][x] != '1' && game->map[y][x] != 'E') || \
		(game->map[y][x] == 'E' && game->check.exit))
		return (1);
	return (0);
}

static void	move_dir(int dir, int x, int y, t_data *game)
{
	if (ft_check_path(x, y, game))
	{
		if (game->map[y][x] == 'E')
			ft_close(game);
		game->content.player.x = x;
		game->content.player.y = y;
		set_img_dir(dir, game->content.player, game);
	}
}

int	key_hook(int keycode, t_data *game)
{
	t_pos	pos;

	pos = game->content.player;
	if (keycode == KEY_ESC)
		ft_close(game);
	else if (keycode == KEY_L && ft_check_path(pos.x - 1, pos.y, game))
		move_dir(KEY_L, pos.x - 1, pos.y, game);
	else if (keycode == KEY_D && ft_check_path(pos.x, pos.y + 1, game))
		move_dir(KEY_D, pos.x, pos.y + 1, game);
	else if (keycode == KEY_R && ft_check_path(pos.x + 1, pos.y, game))
		move_dir(KEY_R, pos.x + 1, pos.y, game);
	else if (keycode == KEY_U && ft_check_path(pos.x, pos.y - 1, game))
		move_dir(KEY_U, pos.x, pos.y - 1, game);
	return (0);
}
