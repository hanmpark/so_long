/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 16:34:17 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/game_bonus.h"
#include "../../../inc/hooks_bonus.h"
#include "../../../inc/move_bonus.h"

static void	new_window(t_data *game, int x, int y)
{
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	render(game);
}

void	data_init(t_data *game)
{
	game->move_pl_px.x = 0;
	game->move_pl_px.y = 0;
	game->hook.dir.left = 0;
	game->hook.dir.right = 0;
	game->hook.dir.down = 0;
	game->hook.dir.up = 0;
	game->hook.anim.left = 0;
	game->hook.anim.right = 0;
	game->hook.anim.down = 0;
	game->hook.anim.up = 0;
	game->hook.is_anim = 0;
	game->frames = 0;
	game->exit = 0;
	game->count_moves = 0;
	game->move_enemy = STILL_ENEMY;
	game->game_state = GAME_ON;
	game->img.current_exit = game->img.exit[0];
}

void	game_init(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game->map, game->enemy, ERR_MLX);
	assign_texture(game);
	data_init(game);
	new_window(game, 832, 704);
	mlx_hook(game->win, 17, 0, &game_close, game);
	mlx_hook(game->win, KEYPRESS, 0, &key_pressed, game);
	mlx_hook(game->win, KEYRELEASE, 0, &key_released, game);
	mlx_loop_hook(game->mlx, &update, game);
	mlx_loop(game->mlx);
}
