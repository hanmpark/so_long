/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:14:22 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/08 14:14:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	content_init(t_cnt *content)
{
	content->isplayer = 0;
	content->collectible = 0;
	content->exit = 0;
	content->player.x = 0;
	content->player.y = 0;
	content->size.x = 0;
	content->size.y = 0;
}

void	assign_texture(t_data *game)
{
	game->sprite.floor = "./sprites/ground.xpm";
	game->sprite.wall = "./sprites/wall.xpm";
	game->sprite.img_wall = mlx_xpm_file_to_image(game->mlx, game->sprite.wall, &(game->sprite.width), &(game->sprite.height));
	ft_printf("img_wall = %p\n", game->sprite.img_wall);
	game->sprite.img_floor = mlx_xpm_file_to_image(game->mlx, game->sprite.floor, &(game->sprite.width), &(game->sprite.height));
	ft_printf("img_floor = %p\n", game->sprite.img_floor);
}