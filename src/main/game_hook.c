/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:04 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/17 00:57:57 by hanmpark         ###   ########.fr       */
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

static void	dir_pressed(t_list *img_dir, t_data *game, int *dir)
{
	if (!*dir)
	{
		ft_printf("PASS\n");
		*dir = 1;
		game->img.current = img_dir;
		game->img.current_back = img_dir;
	}
}

int	key_pressed(int key, t_data *game)
{
	if (key == KEY_ESC)
		ft_close(game);
	else if (key == KEY_L)
		dir_pressed(game->img.left, game, &game->dir.left);
	else if (key == KEY_R)
		dir_pressed(game->img.right, game, &game->dir.right);
	else if (key == KEY_D)
		dir_pressed(game->img.down, game, &game->dir.down);
	else if (key == KEY_U)
		dir_pressed(game->img.up, game, &game->dir.up);
	return (0);
}

int	key_released(int key, t_data *game)
{
	if (key == KEY_L)
		game->dir.left = 0;
	else if (key == KEY_R)
		game->dir.right = 0;
	else if (key == KEY_D)
		game->dir.down = 0;
	else if (key == KEY_U)
		game->dir.up = 0;
	return (0);
}
