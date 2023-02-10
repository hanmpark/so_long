/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:45:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/10 11:50:48 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	print_img(t_data *game, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(game->mlx, game->win.id, img, 64 * x, 64 * y);
}

void	print_background(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if ((j % 2 && !(i % 2)) || (!(j % 2) && i % 2))
				print_img(game, game->sprite.img_floor[0], j, i);
			else
				print_img(game, game->sprite.img_floor[1], j, i);
			if (game->map[i][j] == '1')
				print_img(game, game->sprite.img_wall, j, i);
		}
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
