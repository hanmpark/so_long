/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/27 22:05:47 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/game.h"

static void	new_window(t_data *game, int x, int y)
{
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	render(game, game->map);
}

static void	assign_textures(t_data *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/dir/down/down0.xpm", \
		&game->img.width, &game->img.height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, \
		"./img/collectible/coin0.xpm", \
		&game->img.width, &game->img.height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/wall.xpm", &game->img.width, &game->img.height);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/ground.xpm", &game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/exit0.xpm", &game->img.width, &game->img.height);
}

void	game_init(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game->map, NULL, ERR_MLX);
	assign_textures(game);
	game->exit = 0;
	game->count_moves = 0;
	new_window(game, 64 * game->size.x, 64 * game->size.y);
	mlx_hook(game->win, 17, 0, &game_close, game);
	mlx_hook(game->win, KEYPRESS, 0, &key_pressed, game);
	mlx_loop(game->mlx);
}
