/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:46:23 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/25 16:42:20 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/game.h"
#include "../../libft/inc/ft_printf.h"

void	print_img(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

static void	print_elements(t_data *game, int x, int y)
{
	ft_printf("%c", game->map[y][x]);
	print_img(game, game->img.floor, x, y);
	if (game->map[y][x] == '1')
		print_img(game, game->img.wall, x, y);
	else if (game->map[y][x] == 'C')
		print_img(game, game->img.collectible, x, y);
	else if (game->map[y][x] == 'E')
		print_img(game, game->img.exit, x, y);
	else if (game->map[y][x] == 'P')
		print_img(game, game->img.player, x, y);
}

void	render(t_data *game, char **map)
{
	t_pos	pos;

	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
			print_elements(game, pos.x, pos.y);
		ft_printf("\n");
	}
}
