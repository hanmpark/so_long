/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:45:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 16:07:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

static void	print_elements(t_pos win, t_pos pl, t_data *game)
{
	if ((pl.x % 2 && !(pl.y % 2)) || (!(pl.x % 2) && pl.y % 2))
		print_img(game, game->img.floor[0], win.x, win.y);
	else
		print_img(game, game->img.floor[1], win.x, win.y);
	if (game->map[pl.y][pl.x] == 'C' || game->map[pl.y][pl.x] == 'T')
		print_img(game, game->img.collectible->content, win.x, win.y);
	else if (pl.x == game->map_content.exit_pos.x && \
		pl.y == game->map_content.exit_pos.y)
		print_img(game, game->img.current_exit, win.x, win.y);
	else if (game->map[pl.y][pl.x] == '1')
		print_img(game, game->img.wall, win.x, win.y);
}

static void	print_game(t_data *game, t_pos pl)
{
	int		og;
	t_pos	win;

	og = pl.x;
	win.y = -1;
	while (++win.y < 9)
	{
		win.x = -1;
		pl.x = og;
		while (++win.x < 13)
		{
			if (pl.x < 0 || pl.x >= game->size.x || pl.y < 0 || \
				pl.y >= game->size.y)
			{
				print_img(game, game->img.floor[2], win.x, win.y);
				print_img(game, game->img.wall, win.x, win.y);
			}
			if ((pl.x >= 0 && pl.x < game->size.x) && \
				(pl.y >= 0 && pl.y < game->size.y))
				print_elements(win, pl, game);
			pl.x++;
		}
		pl.y++;
	}
}

static void	print_moves_count(int number, t_data *g)
{
	int	i;
	int	unit;

	i = 0;
	while (i < 4)
	{
		unit = number % 10;
		mlx_put_image_to_window(g->mlx, g->win, g->img.number[unit], \
			454 - ((g->img.width + 8) * i), 593);
		number /= 10;
		i++;
	}
}

int	render(t_data *g)
{
	t_pos	pl;

	pl.y = g->player.y - 4;
	pl.x = g->player.x - 6;
	print_game(g, pl);
	if (g->game_state == GAME_ON || g->game_state == GAME_SUCCESS)
		mlx_put_image_to_window(g->mlx, g->win, g->img.current->content, \
			6 * 64, 4 * 64);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.dead, \
			6 * 64, 4 * 64);
	print_img_mob(g, g->map_content.enemy);
	if (g->game_state == GAME_ON)
		mlx_put_image_to_window(g->mlx, g->win, g->img.border[0], 0, 0);
	else if (g->game_state == GAME_OVER)
		mlx_put_image_to_window(g->mlx, g->win, g->img.border[1], 0, 0);
	else if (g->game_state == GAME_SUCCESS)
		mlx_put_image_to_window(g->mlx, g->win, g->img.border[2], 0, 0);
	print_moves_count(g->count_moves, g);
	return (0);
}
