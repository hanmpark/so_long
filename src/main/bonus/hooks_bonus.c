/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:04 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/25 12:16:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/game_bonus.h"
#include "../../../inc/hooks_bonus.h"
#include "../src/libft/inc/ft_printf.h"

int	game_close(t_data *game)
{
	if (game->map)
		ft_freetab(game->map);
	free(game->enemy);
	clear_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
}

static void	dir_pressed(t_list *img_dir, t_data *game, int *dir)
{
	if (*dir == 0)
	{
		*dir = 1;
		game->img.current = img_dir;
		game->img.current_back = img_dir;
	}
}

int	key_pressed(int key, t_data *game)
{
	if (key == KEY_ESC)
		game_close(game);
	else if (key == KEY_L && game->game_state == GAME_ON)
		dir_pressed(game->img.left, game, &game->hook.dir.left);
	else if (key == KEY_R && game->game_state == GAME_ON)
		dir_pressed(game->img.right, game, &game->hook.dir.right);
	else if (key == KEY_D && game->game_state == GAME_ON)
		dir_pressed(game->img.down, game, &game->hook.dir.down);
	else if (key == KEY_U && game->game_state == GAME_ON)
		dir_pressed(game->img.up, game, &game->hook.dir.up);
	return (0);
}

int	key_released(int key, t_data *game)
{
	if (key == KEY_L && game->game_state == GAME_ON)
		game->hook.dir.left = 0;
	else if (key == KEY_R && game->game_state == GAME_ON)
		game->hook.dir.right = 0;
	else if (key == KEY_D && game->game_state == GAME_ON)
		game->hook.dir.down = 0;
	else if (key == KEY_U && game->game_state == GAME_ON)
		game->hook.dir.up = 0;
	return (0);
}
