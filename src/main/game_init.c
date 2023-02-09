/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/09 10:39:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_close(t_data *data)
{
	if (data->map)
	{
		ft_freetab(data->map);
		mlx_destroy_image(data->mlx, data->sprite.img_floor);
		mlx_destroy_image(data->mlx, data->sprite.img_wall);
		mlx_destroy_window(data->mlx, data->win.id);
	}
	free(data->mlx);
	exit(0);
}

static t_win	new_window(void *mlx, int x, int y)
{
	t_win	win;

	win.id = mlx_new_window(mlx, x, y, "so_long");
	win.size.x = x;
	win.size.y = y;
	return (win);
}

void	game_init(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game->map, ERR_MLX);
	assign_texture(game);
	game->win = new_window(game->mlx, game->sprite.width * game->content.size.x, game->sprite.height * game->content.size.y);
	mlx_loop_hook(game->mlx, &render, game);
	mlx_hook(game->win.id, 17, 0, &ft_close, game);
	mlx_key_hook(game->win.id, key_hook, game);
	// mlx_key_hook(prog.win.id, *ft_input, &prog);
	mlx_loop(game->mlx);
}
