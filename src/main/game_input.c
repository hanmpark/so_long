/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/10 11:54:23 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_pos	set_vector(int x, int y, int dir)
{
	t_pos	vector;

	vector.x = 0;
	vector.y = 0;
	if (dir == KEY_L)
	{
		vector.x = x - 1;
		vector.y = y;
	}
	else if (dir == KEY_D)
	{
		vector.y = y + 1;
		vector.x = x;
	}
	else if (dir == KEY_U)
	{
		vector.x = x;
		vector.y = y - 1;
	}
	else if (dir == KEY_R)
	{
		vector.x = x + 1;
		vector.y = y;
	}
	return (vector);
}

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
	t_pos	new;
	t_pos	curpos;

	new = set_vector(x, y, dir);
	curpos = game->content.player;
	if (ft_check_path(new.x, new.y, game))
	{
		if ((curpos.x % 2 && !(curpos.y % 2)) || (!(curpos.x % 2) && curpos.y % 2))
			print_img(game, game->sprite.img_floor[0], curpos.x, curpos.y);
		else
			print_img(game, game->sprite.img_floor[1], curpos.x, curpos.y);
		if (game->map[new.y][new.x] == 'E')
			ft_close(game);
		game->content.player = new;
		anim_dir(dir, game->content.player, game);
	}
}

int	key_hook(int keycode, t_data *game)
{
	t_pos		pos;

	pos = game->content.player;
	if (keycode == KEY_ESC)
		ft_close(game);
	else if (keycode == KEY_L)
		move_dir(KEY_L, pos.x, pos.y, game);
	else if (keycode == KEY_D && ft_check_path(pos.x, pos.y + 1, game))
		move_dir(KEY_D, pos.x, pos.y, game);
	else if (keycode == KEY_R && ft_check_path(pos.x + 1, pos.y, game))
		move_dir(KEY_R, pos.x, pos.y, game);
	else if (keycode == KEY_U && ft_check_path(pos.x, pos.y - 1, game))
		move_dir(KEY_U, pos.x, pos.y, game);
	return (0);
}