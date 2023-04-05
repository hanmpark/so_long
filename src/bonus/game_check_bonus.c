/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/05 09:22:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

int	check_path(t_data *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

void	check_game(t_data *game, t_pos pl, t_enemy *mob)
{
	int	len;

	len = 0;
	while (len < game->map_content.enemy)
	{
		if (game->game_state == GAME_ON && \
			(pl.x == mob[len].pos.x) && (pl.y == mob[len].pos.y))
		{
			ft_printf("%sGAME OVER\nYou got killed by a slime !%s\n", \
				RED, DEF);
			game->img.current = game->img.dead;
			game->img.current_back = game->img.dead;
			game->game_state = GAME_OVER;
		}
		len++;
	}
}

static void	check_case(int x, int y, t_data *game)
{
	static int	collectible = 0;
	t_pos		exit;

	exit = game->map_content.exit_pos;
	if (exit.x == x && exit.y == y && game->exit)
	{
		ft_printf("%sGAME SUCCESS\nLevel completed in %d moves !%s\n", \
			GREEN, game->count_moves, DEF);
		game->game_state = GAME_SUCCESS;
	}
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
}

void	move_dir(int x, int y, t_data *game)
{
	game->count_moves++;
	ft_printf("Moves : %d\n", game->count_moves);
	check_case(x, y, game);
	game->map[game->player.y][game->player.x] = '0';
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
}
