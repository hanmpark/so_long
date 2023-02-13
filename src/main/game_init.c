/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/13 14:12:23 by hanmpark         ###   ########.fr       */
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
	print_background(game->content.player, game);
}

static int	anim_player(t_data *game)
{
	if (game->left || game->right || game->down || game->up)
		print_background(game->content.player, game);
	if (game->left)
		anim_dir(game, game->sprite.img_left, game->content.player);
	else if (game->right)
		anim_dir(game, game->sprite.img_right, game->content.player);
	else if (game->down)
		anim_dir(game, game->sprite.img_down, game->content.player);
	else if (game->up)
		anim_dir(game, game->sprite.img_up, game->content.player);
	game->left = 0;
	game->right = 0;
	game->down = 0;
	game->up = 0;
	return (0);
}

void	game_init(t_data *game)
{
	game->check = content_init();
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game->map, ERR_MLX);
	assign_texture(game);
	new_window(game, 832, 704);
	mlx_hook(game->win.id, 17, 0, &ft_close, game);
	mlx_hook(game->win.id, KEYPRESS, 0, &key_hook, game);
	mlx_loop_hook(game->mlx, &anim_player, game);
	mlx_loop(game->mlx);
}
