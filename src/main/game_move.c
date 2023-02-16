/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/16 14:48:52 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	ft_check_path(int x, int y, t_data *game)
{
	if ((game->map[y][x] != '1' && game->map[y][x] != 'E') || \
		(game->map[y][x] == 'E' && game->check.exit))
		return (1);
	return (0);
}

static void	move_dir(int x, int y, t_data *game)
{
	if (game->map[y][x] == 'E')
		ft_close(game);
	else if (game->map[y][x] == 'C')
	{
		game->check.collectible++;
		game->map[y][x] = '0';
		if (game->check.collectible == game->map_content.collectible)
			game->check.exit++;
	}
	game->map[game->player.y][game->player.x] = '0';
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
	int	i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
}

static void	pixel_left(t_data *game)
{
	game->is_anim = 1;
	while (game->move.x != 64 && !(game->pl_rate % 20))
		game->move.x += 16;
	game->move.x = 0;
	move_dir(game->player.x - 1, game->player.y, game);
	game->is_anim = 0;
}

static void	pixel_right(t_data *game)
{
	game->is_anim = 1;
	while (game->move.x != -64 && !(game->pl_rate % 20))
		game->move.x -= 16;
	game->move.x = 0;
	move_dir(game->player.x + 1, game->player.y, game);
	game->is_anim = 0;
}

static void	pixel_down(t_data *game)
{
	game->is_anim = 1;
	while (game->move.y != -64 && !(game->pl_rate % 20))
		game->move.y -= 16;
	game->move.y = 0;
	move_dir(game->player.x, game->player.y + 1, game);
	game->is_anim = 0;
}

static void	pixel_up(t_data *game)
{
	game->is_anim = 1;
	while (game->move.y != 64 && !(game->pl_rate % 20))
		game->move.y += 16;
	game->move.y = 0;
	move_dir(game->player.x, game->player.y - 1, game);
	game->is_anim = 0;
}

void	key_hook(t_data *game)
{
	t_pos	pos;

	pos = game->player;
	if (game->dir.left && !game->is_anim && ft_check_path(pos.x - 1, pos.y, game))
		pixel_left(game);
	else if (game->dir.right && !game->is_anim && ft_check_path(pos.x + 1, pos.y, game))
		pixel_right(game);
	else if (game->dir.down && !game->is_anim && ft_check_path(pos.x, pos.y + 1, game))
		pixel_down(game);
	else if (game->dir.up && !game->is_anim && ft_check_path(pos.x, pos.y - 1, game))
		pixel_up(game);
	
}
