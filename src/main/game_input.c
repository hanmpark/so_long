/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/14 14:41:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	set_dir_player(int dir, t_data *game)
{
	static t_imgset	imgtab[] = {
		{KEY_L, 1, 0, 0, 0},
		{KEY_R, 0, 1, 0, 0},
		{KEY_D, 0, 0, 1, 0},
		{KEY_U, 0, 0, 0, 1},
	};
	int				i;

	i = 0;
	while (i < 4)
	{
		if (dir == imgtab[i].dir)
		{
			if (imgtab[i].left == 1)
				game->img.current = game->img.left;
			else if (imgtab[i].right == 1)
				game->img.current = game->img.right;
			else if (imgtab[i].down == 1)
				game->img.current = game->img.down;
			else if (imgtab[i].up == 1)
				game->img.current = game->img.up;
			game->img.current_back = game->img.current;
		}
		i++;
	}
}

static int	ft_check_path(int dir, int x, int y, t_data *game)
{
	set_dir_player(dir, game);
	if (game->map[y][x] == 'C')
	{
		game->check.collectible++;
		game->map[y][x] = '0';
		if (game->check.collectible == game->map_content.collectible)
			game->check.exit++;
		return (1);
	}
	else if ((game->map[y][x] != '1' && game->map[y][x] != 'E') || \
		(game->map[y][x] == 'E' && game->check.exit))
		return (1);
	return (0);
}

static void	move_dir(int x, int y, t_data *game)
{
	if (game->map[y][x] == 'E')
		ft_close(game);
	else
		game->map[game->player.y][game->player.x] = '0';
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
	render(game->player, game);
}

int	key_hook(int keycode, t_data *game)
{
	t_pos	pos;

	pos = game->player;
	if (keycode == KEY_ESC)
		ft_close(game);
	else if (keycode == KEY_L && \
		ft_check_path(keycode, pos.x - 1, pos.y, game))
		move_dir(pos.x - 1, pos.y, game);
	else if (keycode == KEY_D && \
		ft_check_path(keycode, pos.x, pos.y + 1, game))
		move_dir(pos.x, pos.y + 1, game);
	else if (keycode == KEY_R && \
		ft_check_path(keycode, pos.x + 1, pos.y, game))
		move_dir(pos.x + 1, pos.y, game);
	else if (keycode == KEY_U && \
		ft_check_path(keycode, pos.x, pos.y - 1, game))
		move_dir(pos.x, pos.y - 1, game);
	return (0);
}
