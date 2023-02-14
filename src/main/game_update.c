/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/14 23:03:28 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	pressed_anim(t_data *game)
{
	if (game->dir.left || game->dir.right || game->dir.down || game->dir.up)
	{
		if (game->f_rate % 50)
			game->img.current = game->img.current->next;
		if (!game->img.current)
		{
			game->img.current = game->img.current_back;
			game->f_rate = 0;
		}
		game->f_rate++;
	}
	else
		game->img.current = game->img.current_back;
}

int	update(t_data *game)
{
	key_hook(game);
	pressed_anim(game);
	render(game->player, game);
	return (0);
}