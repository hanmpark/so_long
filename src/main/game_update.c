/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/17 00:28:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	is_left(t_data *game)
{
	if ((game->dir.left || game->press.left) && \
		ft_check_path(game->player.x - 1, game->player.y, game) && \
		!game->press.right && !game->press.down && !game->press.up)
	{
		game->press.left = 1;
		if (game->anim_rate && !(game->anim_rate % 5))
			game->move.x += 16;
		game->anim_rate++;
		if (game->move.x == 64)
		{
			game->move.x = 0;
			move_dir(game->player.x - 1, game->player.y, game);
			game->press.left = 0;
			game->anim_rate = 0;
		}
	}
}

static void	is_right(t_data *game)
{
	if ((game->dir.right || game->press.right) && \
		ft_check_path(game->player.x + 1, game->player.y, game) && \
		!game->press.left && !game->press.down && !game->press.up)
	{
		game->press.right = 1;
		if (game->anim_rate && !(game->anim_rate % 5))
			game->move.x -= 16;
		game->anim_rate++;
		if (game->move.x == -64)
		{
			game->move.x = 0;
			move_dir(game->player.x + 1, game->player.y, game);
			game->press.right = 0;
			game->anim_rate = 0;
		}
	}
}

static void	is_down(t_data *game)
{
	if ((game->dir.down || game->press.down) && \
		ft_check_path(game->player.x, game->player.y + 1, game) && \
		!game->press.up && !game->press.left && !game->press.right)
	{
		game->press.down = 1;
		if (game->anim_rate && !(game->anim_rate % 5))
			game->move.y -= 16;
		game->anim_rate++;
		if (game->move.y == -64)
		{
			game->move.y = 0;
			move_dir(game->player.x, game->player.y + 1, game);
			game->press.down = 0;
			game->anim_rate = 0;
		}
	}
}

static void	is_up(t_data *game)
{
	if ((game->dir.up || game->press.up) && \
		ft_check_path(game->player.x, game->player.y - 1, game) && \
		!game->press.down && !game->press.left && !game->press.right)
	{
		game->press.up = 1;
		if (game->anim_rate && !(game->anim_rate % 5))
			game->move.y += 16;
		game->anim_rate++;
		if (game->move.y == 64)
		{
			game->move.y = 0;
			move_dir(game->player.x, game->player.y - 1, game);
			game->press.up = 0;
			game->anim_rate = 0;
		}
	}
}

static void	anim_sprites(t_data *game)
{
	if (game->anim_rate && !(game->anim_rate % 10))
		game->img.current = game->img.current->next;
	if (!game->img.current)
		game->img.current = game->img.current_back;
}

int	update(t_data *game)
{
	is_left(game);
	is_right(game);
	is_down(game);
	is_up(game);
	anim_sprites(game);
	render(game->player, game);
	return (0);
}
