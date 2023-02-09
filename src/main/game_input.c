/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/09 11:12:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// static void	check_pos(t_data *game)
// {

// }

int	key_hook(int keycode, t_data *game)
{
	static int	moves;
	t_pos		pos;

	moves = 1;
	pos = game->content.player;
	ft_printf("Moves: %d\n", moves++);
	if (keycode == 53)
		ft_close(game);
	else if (keycode == 0 && game->map[pos.y][pos.x - 1] != '1')
		game->content.player.x--;
	else if (keycode == 1 && game->map[pos.y + 1][pos.x] != '1')
		game->content.player.y++;
	else if (keycode == 2 && game->map[pos.y][pos.x + 1] != '1')
		game->content.player.x++;
	else if (keycode == 13 && game->map[pos.y - 1][pos.x] != '1')
		game->content.player.y--;
	return (0);
}