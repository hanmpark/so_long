/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:12:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/05 09:24:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	clear_img(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.collectible);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.wall);
}

int	game_close(t_data *game)
{
	if (game->map)
		ft_freetab(game->map);
	clear_img(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
}

int	key_pressed(int key, t_data *game)
{
	t_pos	pl;

	pl = game->player;
	if (key == KEY_ESC)
		game_close(game);
	else if (key == KEY_L && check_path(game, pl.x - 1, pl.y))
		move_player(game, pl.x - 1, pl.y);
	else if (key == KEY_R && check_path(game, pl.x + 1, pl.y))
		move_player(game, pl.x + 1, pl.y);
	else if (key == KEY_D && check_path(game, pl.x, pl.y + 1))
		move_player(game, pl.x, pl.y + 1);
	else if (key == KEY_U && check_path(game, pl.x, pl.y - 1))
		move_player(game, pl.x, pl.y - 1);
	return (0);
}
