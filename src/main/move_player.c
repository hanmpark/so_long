/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:42 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/22 19:55:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	left_direction(t_data *game)
{
	if (!game->hook.anim.right && !game->hook.anim.down && !game->hook.anim.up && \
		ft_check_path(game->player.x - 1, game->player.y, 0, game))
	{
		game->hook.anim.left = 1;
		game->move_pl_px.x += 4;
		if (game->move_pl_px.x == 64)
		{
			game->move_pl_px.x = 0;
			move_dir(game->player.x - 1, game->player.y, game);
			game->hook.anim.left = 0;
		}
	}
}

static void	right_direction(t_data *game)
{
	if (!game->hook.anim.left && !game->hook.anim.down && !game->hook.anim.up && \
		ft_check_path(game->player.x + 1, game->player.y, 0, game))
	{
		game->hook.anim.right = 1;
		game->move_pl_px.x -= 4;
		if (game->move_pl_px.x == -64)
		{
			game->move_pl_px.x = 0;
			move_dir(game->player.x + 1, game->player.y, game);
			game->hook.anim.right = 0;
		}
	}
}

static void	down_direction(t_data *game)
{
	if (!game->hook.anim.up && !game->hook.anim.left && !game->hook.anim.right && \
		ft_check_path(game->player.x, game->player.y + 1, 0, game))
	{
		game->hook.anim.down = 1;
		game->move_pl_px.y -= 4;
		if (game->move_pl_px.y == -64)
		{
			game->move_pl_px.y = 0;
			move_dir(game->player.x, game->player.y + 1, game);
			game->hook.anim.down = 0;
		}
	}
}

static void	up_direction(t_data *game)
{
	if (!game->hook.anim.down && !game->hook.anim.left && !game->hook.anim.right && \
		ft_check_path(game->player.x, game->player.y - 1, 0, game))
	{
		game->hook.anim.up = 1;
		game->move_pl_px.y += 4;
		if (game->move_pl_px.y == 64)
		{
			game->move_pl_px.y = 0;
			move_dir(game->player.x, game->player.y - 1, game);
			game->hook.anim.up = 0;
		}
	}
}

void	move_player(t_data *game)
{
	if (game->game_state == GAME_ON && \
		(game->hook.dir.left || game->hook.anim.left))
		left_direction(game);
	if (game->game_state == GAME_ON && \
		(game->hook.dir.right || game->hook.anim.right))
		right_direction(game);
	if (game->game_state == GAME_ON && \
		(game->hook.dir.down || game->hook.anim.down))
		down_direction(game);
	if (game->game_state == GAME_ON && \
		(game->hook.dir.up || game->hook.anim.up))
		up_direction(game);
}
