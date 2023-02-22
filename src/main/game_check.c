/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/22 19:52:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_check_path(int x, int y, int enemy, t_data *game)
{
	if (game->map[y][x] == '1')
		return (0);
	if (enemy && (game->map[y][x] == 'M' || game->map[y][x] == 'T'))
		return (0);
	return (1);
}

void	check_game(t_pos pl, t_enemy *mob, t_data *game)
{
	int	len;

	len = 0;
	while (len < game->map_content.enemy)
	{
		if (game->game_state == GAME_ON && \
			(pl.x == mob[len].pos.x) && (pl.y == mob[len].pos.y))
		{
			ft_printf("GAME OVER\nYou got killed by a slime !\n");
			game->img.current = game->img.dead;
			game->img.current_back = game->img.dead;
			game->game_state = GAME_OVER;
		}
		len++;
	}
}

void	move_dir(int x, int y, t_data *game)
{
	static int	collectible = 0;
	t_pos		exit;

	game->count_moves++;
	ft_printf("Moves : %d\n", game->count_moves);
	exit = game->map_content.exit_pos;
	if (exit.x == x && exit.y == y && game->exit)
		game->game_state = GAME_SUCCESS;
	else if (game->map[y][x] == 'C')
	{
		collectible++;
		game->map[y][x] = '0';
		if (collectible == game->map_content.collectible)
		{
			game->img.current_exit = game->img.exit[1];
			game->exit = 1;
		}
	}
	game->map[game->player.y][game->player.x] = '0';
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
}
