/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/10 09:04:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_close(t_data *data)
{
	if (data->map)
	{
		ft_freetab(data->map);
		mlx_destroy_window(data->mlx, data->win.id);
	}
	free(data->mlx);
	exit(0);
}

static void	new_window(t_data *game, int x, int y)
{
	game->win.id = mlx_new_window(game->mlx, x, y, "so_long");
	print_background(game);
	print_elements(game);
}

void	game_init(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game->map, ERR_MLX);
	assign_texture(game);
	new_window(game, 64 * game->content.size.x, 64 * game->content.size.y);
	mlx_hook(game->win.id, 17, 0, &ft_close, game);
	mlx_hook(game->win.id, KEYPRESS, 0, &key_hook, game);
	mlx_loop(game->mlx);
}
