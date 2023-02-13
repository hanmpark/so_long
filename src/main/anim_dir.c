/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:45:13 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/13 14:11:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	anim_dir(t_data *game, t_list *img, t_pos m)
{
	t_list		*img_og;
	static int	moves;

	img_og = img;
	moves++;
	ft_printf("Moves %d\n", moves);
	while (img)
	{
		if ((m.x % 2 && !(m.y % 2)) || (!(m.x % 2) && m.y % 2))
			print_img(game, game->sprite.img_floor[0], 6, 4);
		else
			print_img(game, game->sprite.img_floor[1], 6, 4);
		print_img(game, img->content, 6, 4);
		img = img->next;
		ft_printf("pass\n");
	}
	img = img_og;
}

void	set_img_dir(int dir, t_pos pos, t_data *game)
{
	(void)pos;
	if (dir == KEY_L)
		game->left = 1;
	else if (dir == KEY_D)
		game->down = 1;
	else if (dir == KEY_R)
		game->right = 1;
	else if (dir == KEY_U)
		game->up = 1;
}
