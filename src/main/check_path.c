/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/20 15:49:58 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_check_path(int x, int y, t_data *game)
{
	if (game->map[y][x] != '1')
		return (1);
	return (0);
}

void	check_game(t_pos pl, t_enemy *mob, t_data *game)
{
	int	len;

	len = 0;
	while (len < game->map_content.enemy)
	{
		if ((pl.x == mob[len].pos.x) && (pl.y == mob[len].pos.y))
		{
			ft_printf("GAME OVER\nYou got killed by a slime !\n");
			ft_close(game);
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
		ft_close(game);
	else if (game->map[y][x] == 'M' || game->map[y][x] == 'T')
	{
		ft_printf("GAME OVER\nYou got killed by a slime !\n");
		ft_close(game);
	}
	else if (game->map[y][x] == 'C')
	{
		collectible++;
		game->map[y][x] = '0';
		if (collectible == game->map_content.collectible)
		{
			game->img.current_exit = game->img.img_exit[1];
			game->exit++;
		}
	}
	game->map[game->player.y][game->player.x] = '0';
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
}
