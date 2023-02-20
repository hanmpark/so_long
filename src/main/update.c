/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/20 16:33:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	pl_sprites(t_data *game)
{
	if ((game->hook.anim.left || game->hook.anim.right || \
		game->hook.anim.down || game->hook.anim.up) && !(game->frames % 10))
		game->img.current = game->img.current->next;
	if (!game->img.current)
		game->img.current = game->img.current_back;
}

static void	anim_enemy(t_data *game)
{
	if (!(game->frames % 5))
		game->img.mob = game->img.mob->next;
	if (!game->img.mob)
		game->img.mob = game->img.mob_back;
	if (!(game->frames % 100))
		game->move_enemy = 1;
}

int	update(t_data *game)
{
	game->frames++;
	if (game->frames == 200)
		game->frames = 0;
	check_game(game->player, game->enemy, game);
	anim_enemy(game);
	pl_sprites(game);
	if (game->move_enemy == 1)
		move_enemy(game);
	move_player(game);
	render(game);
	return (0);
}
