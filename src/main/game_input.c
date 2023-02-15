/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/15 19:07:34 by hanmpark         ###   ########.fr       */
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
	else
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

static void	pixel_move(t_data *game)
{
	t_pos	pos;

	pos = game->player;
	if (game->dir.left && !(game->f_rate % 5) && ft_check_path(pos.x - 1, pos.y, game))
		game->move.x += 16;
	else if (game->dir.right && !(game->f_rate % 5) && ft_check_path(pos.x + 1, pos.y, game))
		game->move.x -= 16;
	else if (game->dir.down && !(game->f_rate % 5) && ft_check_path(pos.x, pos.y + 1, game))
		game->move.y -= 16;
	else if (game->dir.up && !(game->f_rate % 5) && ft_check_path(pos.x, pos.y - 1, game))
		game->move.y += 16;
	if (game->move.x == 64 || game->move.x == -64)
		game->move.x = 0;
	if (game->move.y == 64 || game->move.y == -64)
		game->move.y = 0;
}

int	key_hook(t_data *game)
{
	t_pos	pos;

	pos = game->player;
	pixel_move(game);
	if (game->dir.left && !(game->f_rate % 5) && game->move.x == 0 && ft_check_path(pos.x - 1, pos.y, game))
	{
		if (game->move.y < 0)
		{
			if (ft_check_path(pos.x - 1, pos.y + 1, game))
				move_dir(pos.x - 1, pos.y, game);
		}
		else if (game->move.y > 0)
		{
			if (ft_check_path(pos.x - 1, pos.y - 1, game))
				move_dir(pos.x - 1, pos.y, game);
		}
		else
			move_dir(pos.x - 1, pos.y, game);
	}
	else if (game->dir.right && !(game->f_rate % 5) && game->move.x == 0 && ft_check_path(pos.x + 1, pos.y, game))
	{
		if (game->move.y < 0)
		{
			if (ft_check_path(pos.x + 1, pos.y + 1, game))
				move_dir(pos.x + 1, pos.y, game);
		}
		else if (game->move.y > 0)
		{
			if (ft_check_path(pos.x + 1, pos.y - 1, game))
				move_dir(pos.x + 1, pos.y, game);
		}
		else
			move_dir(pos.x + 1, pos.y, game);
	}
	else if (game->dir.down && !(game->f_rate % 5) && game->move.y == 0 && ft_check_path(pos.x, pos.y + 1, game))
	{
		if (game->move.x < 0)
		{
			if (ft_check_path(pos.x + 1, pos.y + 1, game))
				move_dir(pos.x, pos.y + 1, game);
		}
		else if (game->move.x > 0)
		{
			if (ft_check_path(pos.x - 1, pos.y + 1, game))
				move_dir(pos.x, pos.y + 1, game);
		}
		else
			move_dir(pos.x, pos.y + 1, game);
	}
	else if (game->dir.up && !(game->f_rate % 5) && game->move.y == 0 && ft_check_path(pos.x, pos.y - 1, game))
	{
		if (game->move.x < 0)
		{
			if (ft_check_path(pos.x + 1, pos.y - 1, game))
				move_dir(pos.x, pos.y - 1, game);
		}
		else if (game->move.x > 0)
		{
			if (ft_check_path(pos.x - 1, pos.y - 1, game))
				move_dir(pos.x, pos.y - 1, game);
		}
		else
			move_dir(pos.x, pos.y - 1, game);
	}
	return (0);
}
