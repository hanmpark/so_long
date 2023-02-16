/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:14:22 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/16 14:33:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_cnt	content_init(void)
{
	t_cnt	content;

	content.isplayer = 0;
	content.collectible = 0;
	content.exit = 0;
	return (content);
}

int	ft_setlen(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

t_list	*load_dir(char *path, t_data *game)
{
	t_list	*img;
	int		set;
	char	*str;
	char	number;

	str = ft_strdup(path);
	img = ft_lstnew(mlx_xpm_file_to_image(game->mlx, str, \
		&game->img.width, &game->img.height));
	number = '1';
	set = ft_setlen(str, '0');
	while (number < '4')
	{
		ft_memset(&str[set], number, 1);
		ft_lstadd_back(&img, ft_lstnew(mlx_xpm_file_to_image(game->mlx, str, \
			&game->img.width, &game->img.height)));
		number++;
	}
	free(str);
	return (img);
}

void	assign_dir_sprites(t_data *game)
{
	game->img.down = load_dir("./sprites/dir/down/down0.xpm", game);
	game->img.up = load_dir("./sprites/dir/up/up0.xpm", game);
	game->img.left = load_dir("./sprites/dir/left/left0.xpm", game);
	game->img.right = load_dir("./sprites/dir/right/right0.xpm", game);
	game->img.current = game->img.down;
	game->img.current_back = game->img.down;
}

void	assign_texture(t_data *game)
{
	assign_dir_sprites(game);
	game->img.floor[0] = "./sprites/ground.xpm";
	game->img.floor[1] = "./sprites/ground1.xpm";
	game->img.floor[2] = "./sprites/ground2.xpm";
	game->img.wall = "./sprites/wall.xpm";
	game->img.collectible = "./sprites/collectible.xpm";
	game->img.exit[0] = "./sprites/exit0.xpm";
	game->img.exit[1] = "./sprites/exit1.xpm";
	game->img.mob = "./sprites/mob.xpm";
	game->img.img_wall = mlx_xpm_file_to_image(game->mlx, game->img.wall, &game->img.width, &game->img.height);
	game->img.img_floor[0] = mlx_xpm_file_to_image(game->mlx, game->img.floor[0], &game->img.width, &game->img.height);
	game->img.img_floor[1] = mlx_xpm_file_to_image(game->mlx, game->img.floor[1], &game->img.width, &game->img.height);
	game->img.img_floor[2] = mlx_xpm_file_to_image(game->mlx, game->img.floor[2], &game->img.width, &game->img.height);
	game->img.img_collectible = mlx_xpm_file_to_image(game->mlx, game->img.collectible, &game->img.width, &game->img.height);
	game->img.img_exit[0] = mlx_xpm_file_to_image(game->mlx, game->img.exit[0], &game->img.width, &game->img.height);
	game->img.img_exit[1] = mlx_xpm_file_to_image(game->mlx, game->img.exit[1], &game->img.width, &game->img.height);
	game->img.img_mob = mlx_xpm_file_to_image(game->mlx, game->img.mob, &game->img.width, &game->img.height);
}