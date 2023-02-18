/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:45:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/18 16:21:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	print_img(t_data *game, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, \
			64 * x + game->move.x, 64 * y + game->move.y);
}

static void	print_elements(t_pos win, t_pos pl, t_data *game)
{
	if ((pl.x % 2 && !(pl.y % 2)) || (!(pl.x % 2) && pl.y % 2))
		print_img(game, game->img.img_floor[0], win.x, win.y);
	else
		print_img(game, game->img.img_floor[1], win.x, win.y);
	if (game->map[pl.y][pl.x] == 'C')
		print_img(game, game->img.img_collectible, win.x, win.y);
	else if (game->map[pl.y][pl.x] == 'E')
		print_img(game, game->img.current_exit, win.x, win.y);
	else if (game->map[pl.y][pl.x] == 'M')
		print_img(game, game->img.mob->content, win.x, win.y);
	else if (game->map[pl.y][pl.x] == '1')
	{
		print_img(game, game->img.img_floor[2], win.x, win.y);
		print_img(game, game->img.img_wall, win.x, win.y);
	}
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
	mlx_put_image_to_window(game->mlx, game->win, game->img.border, 0, 0);
	if (game->anim.left || game->anim.right || game->anim.down || game->anim.up || \
		game->dir.left || game->dir.right || game->dir.down || game->dir.up)
		mlx_put_image_to_window(game->mlx, game->win, game->img.current->content, \
			6 * 64, 4 * 64);
	else if (!game->dir.left && !game->dir.right && !game->dir.down && !game->dir.up && game->frames <= 50)
		mlx_put_image_to_window(game->mlx, game->win, game->img.img_idle[0], \
			6 * 64, 4 * 64);
	else if (!game->dir.left && !game->dir.right && !game->dir.down && !game->dir.up && game->frames < 100)
		mlx_put_image_to_window(game->mlx, game->win, game->img.img_idle[1], \
			6 * 64, 4 * 64);
	return (0);
}
