/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/14 14:47:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	print_anim_sprites(void *img, t_data *game)
{
	if ((game->player.x % 2 && !(game->player.y % 2)) || \
		(!(game->player.x % 2) && game->player.y % 2))
		print_img(game, game->img.img_floor[0], 6, 4);
	else
		print_img(game, game->img.img_floor[1], 6, 4);
	print_img(game, img, 6, 4);
}

static void	set_img_player(t_data *game)
{
	if (game->f_rate == 10)
	{
		game->img.current = game->img.current->next;
		game->f_rate = 0;
	}
	if (!game->img.current)
		game->img.current = game->img.current_back;
	print_anim_sprites(game->img.current->content, game);
}

int	update(t_data *game)
{
	game->f_rate++;
	set_img_player(game);
	return (0);
}