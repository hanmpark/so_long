/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/22 23:47:56 by hanmpark         ###   ########.fr       */
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
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game->map, ERR_MLX);
	assign_texture(game);
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
	game->frames = 0;
	game->exit = 0;
	game->move_enemy = 0;
	game->count_moves = 0;
	game->game_state = GAME_ON;
	game->img.current_exit = game->img.exit[0];
	new_window(game, 832, 704);
}

t_cnt	content_init(void)
{
	t_cnt	content;

	content.isplayer = 0;
	content.collectible = 0;
	content.exit = 0;
	content.enemy = 0;
	content.exit_pos.x = 0;
	content.exit_pos.y = 0;
	return (content);
}

void	game_init(t_data *game)
{
	data_init(game);
	mlx_hook(game->win, 17, 0, &ft_close, game);
	mlx_hook(game->win, KEYPRESS, 0, &key_pressed, game);
	mlx_hook(game->win, KEYRELEASE, 0, &key_released, game);
	mlx_loop_hook(game->mlx, &update, game);
	mlx_loop(game->mlx);
}
