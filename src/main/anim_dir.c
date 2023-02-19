/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:42 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/19 22:50:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	is_left(t_data *game)
{
	if (!game->hook.anim.right && !game->hook.anim.down && !game->hook.anim.up && \
		ft_check_path(game->player.x - 1, game->player.y, game))
	{
		game->hook.anim.left = 1;
		game->move.x += 4;
		if (game->move.x == 64)
		{
			game->move.x = 0;
			move_dir(game->player.x - 1, game->player.y, game);
			game->hook.anim.left = 0;
		}
	}
}

static void	is_right(t_data *game)
{
	if (!game->hook.anim.left && !game->hook.anim.down && !game->hook.anim.up && \
		ft_check_path(game->player.x + 1, game->player.y, game))
	{
		game->hook.anim.right = 1;
		game->move.x -= 4;
		if (game->move.x == -64)
		{
			game->move.x = 0;
			move_dir(game->player.x + 1, game->player.y, game);
			game->hook.anim.right = 0;
		}
	}
}

static void	is_down(t_data *game)
{
	if (!game->hook.anim.up && !game->hook.anim.left && !game->hook.anim.right && \
		ft_check_path(game->player.x, game->player.y + 1, game))
	{
		game->hook.anim.down = 1;
		game->move.y -= 4;
		if (game->move.y == -64)
		{
			game->move.y = 0;
			move_dir(game->player.x, game->player.y + 1, game);
			game->hook.anim.down = 0;
		}
	}
}

static void	is_up(t_data *game)
{
	if (!game->hook.anim.down && !game->hook.anim.left && !game->hook.anim.right && \
		ft_check_path(game->player.x, game->player.y - 1, game))
	{
		game->hook.anim.up = 1;
		game->move.y += 4;
		if (game->move.y == 64)
		{
			game->move.y = 0;
			move_dir(game->player.x, game->player.y - 1, game);
			game->hook.anim.up = 0;
		}
	}
}

void	anim_dir(t_data *game)
{
	if (game->hook.dir.left || game->hook.anim.left)
		is_left(game);
	if (game->hook.dir.right || game->hook.anim.right)
		is_right(game);
	if (game->hook.dir.down || game->hook.anim.down)
		is_down(game);
	if (game->hook.dir.up || game->hook.anim.up)
		is_up(game);
}
