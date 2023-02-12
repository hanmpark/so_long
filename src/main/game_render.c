/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:45:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/12 22:08:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	print_img(t_data *game, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(game->mlx, game->win.id, img, 64 * x, 64 * y);
}

static void	print_elements(int x, int y, t_pos mappos, t_data *game)
{
	if ((mappos.x % 2 && !(mappos.y % 2)) || (!(mappos.x % 2) && mappos.y % 2))
		print_img(game, game->sprite.img_floor[0], x, y);
	else
		print_img(game, game->sprite.img_floor[1], x, y);
	if (game->map[mappos.y][mappos.x] == 'C')
		print_img(game, game->sprite.img_collectible, x, y);
	else if (game->map[mappos.y][mappos.x] == 'E')
		print_img(game, game->sprite.img_exit[0], x, y);
	else if (game->map[mappos.y][mappos.x] == 'M')
		print_img(game, game->sprite.img_mob, x, y);
	else if (game->map[mappos.y][mappos.x] == '1')
	{
		print_img(game, game->sprite.img_floor[2], x, y);
		print_img(game, game->sprite.img_wall, x, y);
	}
}

static void	print_game(t_pos m, t_data *game)
{
	int		og;
	t_pos	win;

	og = m.x;
	win.x = 0;
	win.y = 0;
	while (win.y < 9)
	{
		win.x = 0;
		m.x = og;
		while (win.x < 13)
		{
			if (m.x < 0 || m.x >= game->content.size.x || m.y < 0 || \
				m.y >= game->content.size.y)
				print_img(game, game->sprite.img_floor[2], win.x, win.y);
			if ((m.x >= 0 && m.x < game->content.size.x) && \
				(m.y >= 0 && m.y < game->content.size.y))
				print_elements(win.x, win.y, m, game);
			win.x++;
			m.x++;
		}
		win.y++;
		m.y++;
	}
}
// if (win.x == 6 && win.y == 4)

void	print_background(t_list *img_player, t_pos mappos, t_data *game)
{
	t_pos	win_middle;

	mappos.x -= 6;
	mappos.y -= 4;
	print_game(mappos, game);
	mappos.x += 6;
	mappos.y += 4;
	win_middle.x = 6;
	win_middle.y = 4;
	anim_dir(game, img_player, win_middle, mappos);
}
