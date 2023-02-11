/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:45:13 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/11 16:47:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_img	set_img(char *path, t_data *game)
{
	t_img	img;

	
	return (img);
}

void	anim_dir(int dir, t_pos pos, t_data *game)
{
	t_img	img;

	if (dir == KEY_L)
		load_dir("./sprites/dir/left/left0.xpm", &game->sprite.img);
	else if (dir == KEY_D)
		game->sprite.img_down = load_dir("./sprites/dir/down/down0.xpm", game);
	else if (dir == KEY_R)
		game->sprite.img_right = game->sprite.img_right;
	else if (dir == KEY_U)
		game->sprite.img_up = game->sprite.img_up;
	print_background(img, pos, game);
}
