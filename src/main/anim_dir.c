/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:45:13 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/10 19:22:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	anim_dir(int dir, t_pos pos, t_data *game)
{
	void	*img;

	img = 0;
	if (dir == KEY_L)
		img = game->sprite.img_left;
	else if (dir == KEY_D)
		img = game->sprite.img_down;
	else if (dir == KEY_R)
		img = game->sprite.img_right;
	else if (dir == KEY_U)
		img = game->sprite.img_up;
	print_background(img, pos, game);
}
