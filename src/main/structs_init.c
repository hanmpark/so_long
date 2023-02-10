/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:14:22 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/10 13:24:57 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_cnt	content_init(void)
{
	t_cnt	content;

	content.isplayer = 0;
	content.collectible = 0;
	content.exit = 0;
	content.player.x = 0;
	content.player.y = 0;
	content.size.x = 0;
	content.size.y = 0;
	return (content);
}

void	assign_texture(t_data *game)
{
	game->sprite.down = "./sprites/dir/down.xpm";
	game->sprite.left = "./sprites/dir/left.xpm";
	game->sprite.right = "./sprites/dir/right.xpm";
	game->sprite.up = "./sprites/dir/up.xpm";
	game->sprite.floor[0] = "./sprites/ground.xpm";
	game->sprite.floor[1] = "./sprites/ground1.xpm";
	game->sprite.wall = "./sprites/wall.xpm";
	game->sprite.collectible = "./sprites/collectible.xpm";
	game->sprite.exit[0] = "./sprites/exit0.xpm";
	game->sprite.exit[1] = "./sprites/exit1.xpm";
	game->sprite.mob = "./sprites/mob.xpm";
	game->sprite.img_down = mlx_xpm_file_to_image(game->mlx, game->sprite.down, &game->sprite.width, &game->sprite.height);
	game->sprite.img_left = mlx_xpm_file_to_image(game->mlx, game->sprite.left, &game->sprite.width, &game->sprite.height);
	game->sprite.img_right = mlx_xpm_file_to_image(game->mlx, game->sprite.right, &game->sprite.width, &game->sprite.height);
	game->sprite.img_up = mlx_xpm_file_to_image(game->mlx, game->sprite.up, &game->sprite.width, &game->sprite.height);
	game->sprite.img_wall = mlx_xpm_file_to_image(game->mlx, game->sprite.wall, &game->sprite.width, &game->sprite.height);
	game->sprite.img_floor[0] = mlx_xpm_file_to_image(game->mlx, game->sprite.floor[0], &game->sprite.width, &game->sprite.height);
	game->sprite.img_floor[1] = mlx_xpm_file_to_image(game->mlx, game->sprite.floor[1], &game->sprite.width, &game->sprite.height);
	game->sprite.img_collectible = mlx_xpm_file_to_image(game->mlx, game->sprite.collectible, &game->sprite.width, &game->sprite.height);
	game->sprite.img_exit[0] = mlx_xpm_file_to_image(game->mlx, game->sprite.exit[0], &game->sprite.width, &game->sprite.height);
	game->sprite.img_exit[1] = mlx_xpm_file_to_image(game->mlx, game->sprite.exit[1], &game->sprite.width, &game->sprite.height);
	game->sprite.img_mob = mlx_xpm_file_to_image(game->mlx, game->sprite.mob, &game->sprite.width, &game->sprite.height);
}