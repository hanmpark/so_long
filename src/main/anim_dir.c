/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:45:13 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/12 22:41:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	anim_dir(t_data *game, t_list *img, t_pos win, t_pos m)
{
	static int	moves;

	moves++;
	ft_printf("Moves %d\n", moves);
	while (img)
	{
		if ((m.x % 2 && !(m.y % 2)) || (!(m.x % 2) && m.y % 2))
			print_img(game, game->sprite.img_floor[0], win.x, win.y);
		else
			print_img(game, game->sprite.img_floor[1], win.x, win.y);
		print_img(game, img->content, win.x, win.y);
		img = img->next;
	}
}

void	set_img_dir(int dir, t_pos pos, t_data *game)
{
	t_list	*img;

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
