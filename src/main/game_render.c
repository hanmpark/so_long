/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:45:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/21 15:55:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	print_img(t_data *game, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, \
			64 * x + game->move_pl_px.x, 64 * y + game->move_pl_px.y);
}

void	print_img_mob(t_data *g, int enemy_number)
{
	int		number;
	t_pos	pos;

	number = 0;
	while (number < enemy_number)
	{
		pos.x = g->enemy[number].pos.x - (g->player.x - 6);
		pos.y = g->enemy[number].pos.y - (g->player.y - 4);
		if ((pos.x >= 0 && pos.x <= 12) && (pos.y >= 0 && pos.y <= 8))
			mlx_put_image_to_window(g->mlx, g->win, g->img.mob->content, \
				64 * pos.x + (g->move_pl_px.x + g->enemy[number].move_px), \
				64 * pos.y + (g->move_pl_px.y));
		number++;
	}
}

static void	print_elements(t_pos win, t_pos pl, t_data *game)
{
	if ((pl.x % 2 && !(pl.y % 2)) || (!(pl.x % 2) && pl.y % 2))
		print_img(game, game->img.img_floor[0], win.x, win.y);
	else
		print_img(game, game->img.img_floor[1], win.x, win.y);
	if (game->map[pl.y][pl.x] == 'C' || game->map[pl.y][pl.x] == 'T')
		print_img(game, game->img.img_collectible, win.x, win.y);
	else if (pl.x == game->map_content.exit_pos.x && \
		pl.y == game->map_content.exit_pos.y)
		print_img(game, game->img.current_exit, win.x, win.y);
	else if (game->map[pl.y][pl.x] == '1')
		print_img(game, game->img.img_wall, win.x, win.y);
}

static void	print_game(t_data *game)
{
	t_pos	pl;
	int		og;
	t_pos	win;

	pl.y = game->player.y - 4;
	pl.x = game->player.x - 6;
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
				print_img(game, game->img.img_floor[2], win.x, win.y);
			if ((pl.x >= 0 && pl.x < game->size.x) && \
				(pl.y >= 0 && pl.y < game->size.y))
				print_elements(win, pl, game);
			pl.x++;
		}
		pl.y++;
	}
}

int	render(t_data *game)
{
	print_game(game);
	print_img_mob(game, game->map_content.enemy);
	mlx_put_image_to_window(game->mlx, game->win, game->img.current->content, \
		6 * 64, 4 * 64);
	mlx_put_image_to_window(game->mlx, game->win, game->img.border, 0, 0);
	return (0);
}
