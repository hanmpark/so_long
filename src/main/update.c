/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/17 10:46:12 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	anim_sprites(t_data *game)
{
	if (game->press.left || game->press.right || game->press.down || \
		game->press.up)
		game->anim_rate++;
	if (game->anim_rate && !(game->anim_rate % 10))
	{
		game->img.current = game->img.current->next;
		game->anim_rate = 0;
	}
	if (!game->img.current)
		game->img.current = game->img.current_back;
}

int	update(t_data *game)
{
	anim_dir(game);
	anim_sprites(game);
	return (0);
}
