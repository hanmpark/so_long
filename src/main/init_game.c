/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/17 09:55:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	new_window(t_data *game, int x, int y)
{
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	render(game);
}

static void	data_init(t_data *game)
{
	game->check = content_init();
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game->map, ERR_MLX);
	game->move.x = 0;
	game->move.y = 0;
	game->dir.left = 0;
	game->dir.right = 0;
	game->dir.down = 0;
	game->dir.up = 0;
	game->anim_rate = 0;
	game->press.left = 0;
	game->press.right = 0;
	game->press.down = 0;
	game->press.up = 0;
	assign_texture(game);
}

void	game_init(t_data *game)
{
	data_init(game);
	new_window(game, 832, 704);
	mlx_hook(game->win, 17, 0, &ft_close, game);
	mlx_hook(game->win, KEYPRESS, 0, &key_pressed, game);
	mlx_hook(game->win, KEYRELEASE, 0, &key_released, game);
	mlx_loop_hook(game->mlx, &update, game);
	mlx_loop(game->mlx);
}
