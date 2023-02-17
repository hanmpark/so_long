/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/17 17:36:54 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	pl_sprites(t_data *game)
{
	if ((game->anim.left || game->anim.right || game->anim.down || \
		game->anim.up) && !(game->frames % 10))
	{
		game->img.current = game->img.current->next;
		game->pl_rate = 0;
	}
	if (!game->img.current)
		game->img.current = game->img.current_back;
}

static void	anim_mob(t_data *game)
{
	if (!(game->frames % 17))
		game->img.mob = game->img.mob->next;
	if (!game->img.mob)
		game->img.mob = game->img.mob_back;
}

int	update(t_data *game)
{
	game->frames++;
	if (game->frames == 1000)
		game->frames = 0;
	pl_sprites(game);
	anim_mob(game);
	anim_dir(game);
	render(game);
	return (0);
}
