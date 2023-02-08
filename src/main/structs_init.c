/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:14:22 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/08 20:43:22 by hanmpark         ###   ########.fr       */
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
	game->sprite.player[0] = "./sprites/player.xpm";
	game->sprite.player[1] = "./sprites/player1.xpm";
	game->sprite.player[2] = "./sprites/player2.xpm";
	game->sprite.player[3] = "./sprites/player3.xpm";
	game->sprite.player[4] = "./sprites/player4.xpm";
	game->sprite.player[5] = "./sprites/player5.xpm";
	game->sprite.player[6] = "./sprites/player6.xpm";
	game->sprite.floor = "./sprites/ground.xpm";
	game->sprite.floor1 = "./sprites/ground1.xpm";
	game->sprite.wall = "./sprites/wall.xpm";
	game->sprite.collectible = "./sprites/collectible.xpm";
	game->sprite.exit = "./sprites/exit.xpm";
	game->sprite.mob = "./sprites/mob.xpm";
	game->sprite.img_player[0] = mlx_xpm_file_to_image(game->mlx, game->sprite.player[0], &game->sprite.width, &game->sprite.height);
	game->sprite.img_player[1] = mlx_xpm_file_to_image(game->mlx, game->sprite.player[1], &game->sprite.width, &game->sprite.height);
	game->sprite.img_player[2] = mlx_xpm_file_to_image(game->mlx, game->sprite.player[2], &game->sprite.width, &game->sprite.height);
	game->sprite.img_player[3] = mlx_xpm_file_to_image(game->mlx, game->sprite.player[3], &game->sprite.width, &game->sprite.height);
	game->sprite.img_player[4] = mlx_xpm_file_to_image(game->mlx, game->sprite.player[4], &game->sprite.width, &game->sprite.height);
	game->sprite.img_player[5] = mlx_xpm_file_to_image(game->mlx, game->sprite.player[5], &game->sprite.width, &game->sprite.height);
	game->sprite.img_player[6] = mlx_xpm_file_to_image(game->mlx, game->sprite.player[6], &game->sprite.width, &game->sprite.height);
	game->sprite.img_wall = mlx_xpm_file_to_image(game->mlx, game->sprite.wall, &game->sprite.width, &game->sprite.height);
	game->sprite.img_floor = mlx_xpm_file_to_image(game->mlx, game->sprite.floor, &game->sprite.width, &game->sprite.height);
	game->sprite.img_floor1 = mlx_xpm_file_to_image(game->mlx, game->sprite.floor1, &game->sprite.width, &game->sprite.height);
	game->sprite.img_collectible = mlx_xpm_file_to_image(game->mlx, game->sprite.collectible, &game->sprite.width, &game->sprite.height);
	game->sprite.img_exit = mlx_xpm_file_to_image(game->mlx, game->sprite.exit, &game->sprite.width, &game->sprite.height);
	game->sprite.img_mob = mlx_xpm_file_to_image(game->mlx, game->sprite.mob, &game->sprite.width, &game->sprite.height);
}