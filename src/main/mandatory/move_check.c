/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:05:28 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 18:31:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/game.h"
#include "../src/libft/inc/ft_printf.h"

int	check_path(t_data *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

static void	check_case(t_data *game, int x, int y)
{
	static int	collectible = 0;
	t_pos		exit;

	exit = game->map_content.exit_pos;
	if (exit.x == x && exit.y == y && game->exit)
	{
		ft_printf("%sGAME SUCCESS\nLevel completed in %d moves !%s\n", \
			GREEN, game->count_moves, DEF);
		game_close(game);
	}
	else if (game->map[y][x] == 'C')
	{
		collectible++;
		game->map[y][x] = '0';
		if (collectible == game->map_content.collectible)
			game->exit = 1;
	}
}

void	move_player(t_data *game, int x, int y)
{
	t_pos	pl;

	pl = game->player;
	game->count_moves++;
	ft_printf("Moves: %d\n", game->count_moves);
	check_case(game, x, y);
	game->map[pl.y][pl.x] = '0';
	print_img(game, game->img.floor, pl.x, pl.y);
	print_img(game, game->img.player, x, y);
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
}
