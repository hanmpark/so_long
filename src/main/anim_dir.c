/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:42 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/18 15:09:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	is_left(t_data *game)
{
	if (!game->anim.right && !game->anim.down && !game->anim.up && \
		ft_check_path(game->player.x - 1, game->player.y, game))
	{
		game->anim.left = 1;
		game->move.x += 4;
		if (game->move.x == 64)
		{
			game->move.x = 0;
			move_dir(game->player.x - 1, game->player.y, game);
			game->anim.left = 0;
		}
	}
}

static void	is_right(t_data *game)
{
	if (!game->anim.left && !game->anim.down && !game->anim.up && \
		ft_check_path(game->player.x + 1, game->player.y, game))
	{
		game->anim.right = 1;
		game->move.x -= 4;
		if (game->move.x == -64)
		{
			game->move.x = 0;
			move_dir(game->player.x + 1, game->player.y, game);
			game->anim.right = 0;
		}
	}
}

static void	is_down(t_data *game)
{
	if (!game->anim.up && !game->anim.left && !game->anim.right && \
		ft_check_path(game->player.x, game->player.y + 1, game))
	{
		game->anim.down = 1;
		game->move.y -= 4;
		if (game->move.y == -64)
		{
			game->move.y = 0;
			move_dir(game->player.x, game->player.y + 1, game);
			game->anim.down = 0;
		}
	}
}

static void	is_up(t_data *game)
{
	if (!game->anim.down && !game->anim.left && !game->anim.right && \
		ft_check_path(game->player.x, game->player.y - 1, game))
	{
		game->anim.up = 1;
		game->move.y += 4;
		if (game->move.y == 64)
		{
			game->move.y = 0;
			move_dir(game->player.x, game->player.y - 1, game);
			game->anim.up = 0;
		}
	}
}

void	anim_dir(t_data *game)
{
	if (game->dir.left || game->anim.left)
		is_left(game);
	if (game->dir.right || game->anim.right)
		is_right(game);
	if (game->dir.down || game->anim.down)
		is_down(game);
	if (game->dir.up || game->anim.up)
		is_up(game);
}
