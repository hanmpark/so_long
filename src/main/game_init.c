/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/14 14:52:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_close(t_data *game)
{
	if (game->map)
	{
		ft_freetab(game->map);
		mlx_destroy_window(game->mlx, game->win);
	}
	free(game->mlx);
	exit(0);
}

static void	new_window(t_data *game, int x, int y)
{
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	render(game->player, game);
}

void	game_init(t_data *game)
{
	game->check = content_init();
	game->mlx = mlx_init();
	game->f_rate = 0;
	if (!game->mlx)
		ft_error(game->map, ERR_MLX);
	assign_texture(game);
	new_window(game, 832, 704);
	mlx_hook(game->win, 17, 0, &ft_close, game);
	mlx_hook(game->win, KEYPRESS, 0, &key_hook, game);
	mlx_loop_hook(game->mlx, &update, game);
	mlx_loop(game->mlx);
}
