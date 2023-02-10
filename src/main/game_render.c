/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:45:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/10 20:27:43 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	print_img(t_data *game, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(game->mlx, game->win.id, img, 64 * x, 64 * y);
}

/*
111111111
100000001
100000001
100000001
1000P0001
100000001
100000001
100000001
111111111
*/

static t_gap	print_horizontal_outmap(t_pos outmap, t_data *game)
{
	t_gap	gap;
	t_pos	pos;

	gap.min = 0;
	gap.max = 9;
	pos.x = 0;
	while (outmap.x++ < 0)
	{
		pos.y = 0;
		while (pos.y++ < 8)
		{
			print_img(game, game->sprite.img_floor[1], pos.x, pos.y);
			print_img(game, game->sprite.img_wall, pos.x, pos.y);
		}
		pos.x++;
		gap.min = pos.x;
	}
	pos.x = 8;
	while (outmap.x-- + 8 > game->content.size.x)
	{
		pos.y = 0;
		while (pos.y++ < 8)
		{
			print_img(game, game->sprite.img_floor[1], pos.x, pos.y);
			print_img(game, game->sprite.img_wall, pos.x, pos.y);
		}
		gap.max = pos.x;
		pos.x--;
	}
	return (gap);
}

static t_gap	print_vertical_outmap(t_pos outmap, t_data *game)
{
	t_gap	gap;
	t_pos	pos;

	gap.min = 0;
	gap.max = 9;
	pos.y = 0;
	while (outmap.y++ < 0)
	{
		pos.x = 0;
		while (pos.x++ < 8)
		{
			print_img(game, game->sprite.img_floor[1], pos.x, pos.y);
			print_img(game, game->sprite.img_wall, pos.x, pos.y);
		}
		pos.y++;
		gap.min = pos.y;
	}
	pos.y = 8;
	while (outmap.y-- + 8 > game->content.size.y)
	{
		pos.x = 0;
		while (pos.x++ < 8)
		{
			print_img(game, game->sprite.img_floor[1], pos.x, pos.y);
			print_img(game, game->sprite.img_wall, pos.x, pos.y);
		}
		gap.max = pos.y;
		pos.y--;
	}
	return (gap);
}

void	print_elementss(int x, int y, t_pos mappos, t_data *game)
{
	if (game->map[mappos.y][mappos.x] == 'C')
		print_img(game, game->sprite.img_collectible, x, y);
	else if (game->map[mappos.y][mappos.x] == 'E')
		print_img(game, game->sprite.img_exit[0], x, y);
	else if (game->map[mappos.y][mappos.x] == 'M')
		print_img(game, game->sprite.img_mob, x, y);
	else if (game->map[mappos.y][mappos.x] == '1')
		print_img(game, game->sprite.img_wall, x, y);
}

// winpos.x = 0 == mappos.x - 4;
void	brouillon(void *img_player, t_pos mappos, t_data *game)
{
	t_pos	winpos;
	t_pos	maxpos;
	int		i;

	winpos.x = 0;
	winpos.y = 0;
	mappos.x -= 4;
	mappos.y -= 4;
	maxpos.x = game->content.size.x;
	maxpos.y = game->content.size.y;
	i = mappos.x;
	while (mappos.y++ < 0)
	{
		winpos.x = 0;
		while (winpos.x < 9)
		{
			print_img(game, game->sprite.img_floor[1], winpos.x, winpos.y);
			print_img(game, game->sprite.img_wall, winpos.x, winpos.y);
			winpos.x++;
		}
		winpos.y++;
	}
	while (winpos.y < 9)
	{
		winpos.x = 0;
		while (winpos.x < 9)
		{
			if (mappos.x < 0 || mappos.x > maxpos.x)
			{
				print_img(game, game->sprite.img_floor[1], winpos.x, winpos.y);
				print_img(game, game->sprite.img_wall, winpos.x, winpos.y);
			}
			else if ((mappos.x % 2 && !(mappos.y % 2)) || (!(mappos.x % 2) && mappos.y % 2))
				print_img(game, game->sprite.img_floor[0], winpos.x, winpos.y);
			else
				print_img(game, game->sprite.img_floor[1], winpos.x, winpos.y);
			if (!(mappos.x < 0) || !(mappos.y < 0))
				print_elementss(winpos.x, winpos.y, mappos, game);
			if (mappos.x == 4 && mappos.y == 4)
				print_img(game, img_player, winpos.x, winpos.y);
			winpos.x++;
			mappos.x++;
		}
		winpos.y++;
	}
}

void	print_background(void *img_player, t_pos pos, t_data *game)
{
	t_pos	winpos;
	t_gap	y;
	t_gap	x;
	int		i;

	winpos.x = pos.x - 4;
	winpos.y = pos.y - 4;
	y = print_vertical_outmap(winpos, game);
	x = print_horizontal_outmap(winpos, game);
	while (y.min < y.max)
	{
		i = x.min;
		while (i < x.max)
		{
			if ((i % 2 && !(y.min % 2)) || (!(x.min % 2) && y.min % 2))
				print_img(game, game->sprite.img_floor[0], i, y.min);
			else
				print_img(game, game->sprite.img_floor[1], i, y.min);
			i++;
			if (game->map[y.min][i] == '1')
				print_img(game, game->sprite.img_wall, i, y.min);
			else if (game->map[y.min][i] == 'C')
				print_img(game, game->sprite.img_collectible, i, y.min);
			else if (game->map[y.min][i] == 'E')
				print_img(game, game->sprite.img_exit[0], i, y.min);
			else if (game->map[y.min][i] == 'M')
				print_img(game, game->sprite.img_mob, i, y.min);
			print_img(game, img_player, pos.x, pos.y);
		}
		y.min++;
	}
}

void	print_elements(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				print_img(game, game->sprite.img_collectible, j, i);
			else if (game->map[i][j] == 'E')
				print_img(game, game->sprite.img_exit[1], j, i);
			else if (game->map[i][j] == 'M')
				print_img(game, game->sprite.img_mob, j, i);
		}
	}
	print_img(game, game->sprite.img_down, game->content.player.x, game->content.player.y);
}

// static void	print_animation(t_data *game)
// {
	
// }

// int	render(t_data *game)
// {
// 	// print_background(game);
// 	// print_elements(game);
// 	// print_animation(game);
// 	return (0);
// }
