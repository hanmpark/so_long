/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:49:07 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/22 07:23:43 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	set_enemy_letter(int dir, t_enemy *en, t_data *game)
{
	if (game->map[en->pos.y][en->pos.x] == 'T')
		game->map[en->pos.y][en->pos.x] = 'C';
	else
		game->map[en->pos.y][en->pos.x] = '0';
	if (dir == LEFT)
	{
		if (game->map[en->pos.y][en->pos.x - 1] == 'C')
			game->map[en->pos.y][en->pos.x - 1] = 'T';
		else
			game->map[en->pos.y][en->pos.x - 1] = 'M';
	}
	else if (dir == RIGHT)
	{
		if (game->map[en->pos.y][en->pos.x + 1] == 'C')
			game->map[en->pos.y][en->pos.x + 1] = 'T';
		else
			game->map[en->pos.y][en->pos.x + 1] = 'M';
	}
}

static void	move_enemy_px(t_enemy *en, t_data *game, int pixel, int dir)
{
	en->move_px += pixel;
	if (en->move_px == 64 || en->move_px == -64)
	{
		en->move_px = 0;
		game->move_enemy = 0;
		if (dir == LEFT)
		{
			set_enemy_letter(LEFT, en, game);
			en->pos.x -= 1;
			if (!ft_check_path(en->pos.x - 1, en->pos.y, 1, game))
				en->dir = RIGHT;
		}
		else if (dir == RIGHT)
		{
			set_enemy_letter(RIGHT, en, game);
			en->pos.x += 1;
			if (!ft_check_path(en->pos.x + 1, en->pos.y, 1, game))
				en->dir = LEFT;
		}
	}
}

void	move_enemy(t_data *game)
{
	t_enemy	*en;
	int		i;

	en = game->enemy;
	i = 0;
	while (i < game->map_content.enemy)
	{
		if (en[i].dir == LEFT)
			move_enemy_px(&en[i], game, -2, LEFT);
		else if (en[i].dir == RIGHT)
			move_enemy_px(&en[i], game, 2, RIGHT);
		i++;
	}
}
