/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:42 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/17 10:45:17 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	is_left(t_data *game)
{
	if (!game->press.right && !game->press.down && !game->press.up && \
		ft_check_path(game->player.x - 1, game->player.y, game))
	{
		game->press.left = 1;
		game->move.x += 4;
		if (game->move.x == 64)
		{
			game->move.x = 0;
			move_dir(game->player.x - 1, game->player.y, game);
			game->press.left = 0;
		}
		render(game);
	}
}

static void	is_right(t_data *game)
{
	if (!game->press.left && !game->press.down && !game->press.up && \
		ft_check_path(game->player.x + 1, game->player.y, game))
	{
		game->press.right = 1;
		game->move.x -= 4;
		if (game->move.x == -64)
		{
			game->move.x = 0;
			move_dir(game->player.x + 1, game->player.y, game);
			game->press.right = 0;
		}
		render(game);
	}
}

static void	is_down(t_data *game)
{
	if (!game->press.up && !game->press.left && !game->press.right && \
		ft_check_path(game->player.x, game->player.y + 1, game))
	{
		game->press.down = 1;
		game->move.y -= 4;
		if (game->move.y == -64)
		{
			game->move.y = 0;
			move_dir(game->player.x, game->player.y + 1, game);
			game->press.down = 0;
		}
		render(game);
	}
}

static void	is_up(t_data *game)
{
	if (!game->press.down && !game->press.left && !game->press.right && \
		ft_check_path(game->player.x, game->player.y - 1, game))
	{
		game->press.up = 1;
		game->move.y += 4;
		if (game->move.y == 64)
		{
			game->move.y = 0;
			move_dir(game->player.x, game->player.y - 1, game);
			game->press.up = 0;
		}
		render(game);
	}
}

void	anim_dir(t_data *game)
{
	if (game->dir.left || game->press.left)
		is_left(game);
	if (game->dir.right || game->press.right)
		is_right(game);
	if (game->dir.down || game->press.down)
		is_down(game);
	if (game->dir.up || game->press.up)
		is_up(game);
}
