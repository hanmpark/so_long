/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/08 22:45:04 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	ft_close(void)
{
	exit(0);
}

static t_win	new_window(void *mlx, int x, int y)
{
	t_win	win;

	win.id = mlx_new_window(mlx, x, y, "so_long");
	win.size.x = x;
	win.size.y = y;
	mlx_hook(win.id, 17, 0, &ft_close, 0);
	return (win);
}

static void	end(t_data *data)
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

void	game_init(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game->map,ERR_MLX);
	assign_texture(game);
	game->win = new_window(game->mlx, game->sprite.width * game->content.size.x, game->sprite.height * game->content.size.y);
	mlx_loop_hook(game->mlx, &render, game);
	// mlx_key_hook(prog.win.id, *ft_input, &prog);
	mlx_loop(game->mlx);
	end(game);
}
