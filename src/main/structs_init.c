/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:14:22 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/20 12:29:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_cnt	content_init(void)
{
	t_cnt	content;

	content.isplayer = 0;
	content.collectible = 0;
	content.exit = 0;
	content.enemy = 0;
	content.exit_pos.x = 0;
	content.exit_pos.y = 0;
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

static t_list	*load_dir(char *path, char times, t_data *game)
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
	while (number < times)
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
	game->img.down = load_dir("./sprites/dir/down/down0.xpm", '4', game);
	game->img.up = load_dir("./sprites/dir/up/up0.xpm", '4', game);
	game->img.left = load_dir("./sprites/dir/left/left0.xpm", '4', game);
	game->img.right = load_dir("./sprites/dir/right/right0.xpm", '4', game);
	game->img.current = game->img.down;
	game->img.current_back = game->img.down;
	game->img.mob = load_dir("./sprites/mob/mob0.xpm", '8', game);
	ft_lstadd_back(&game->img.mob, ft_lstnew(mlx_xpm_file_to_image(game->mlx, \
		"./sprites/mob/mob1.xpm", &game->img.width, &game->img.height)));
	ft_lstadd_back(&game->img.mob, ft_lstnew(mlx_xpm_file_to_image(game->mlx, \
		"./sprites/mob/mob2.xpm", &game->img.width, &game->img.height)));
	ft_lstadd_back(&game->img.mob, ft_lstnew(mlx_xpm_file_to_image(game->mlx, \
		"./sprites/mob/mob1.xpm", &game->img.width, &game->img.height)));
	game->img.mob_back = game->img.mob;
}

void	assign_texture(t_data *game)
{
	assign_dir_sprites(game);
	game->img.img_wall = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/wall.xpm", &game->img.width, &game->img.height);
	game->img.img_floor[0] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/ground.xpm", &game->img.width, &game->img.height);
	game->img.img_floor[1] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/ground1.xpm", &game->img.width, &game->img.height);
	game->img.img_floor[2] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/ground2.xpm", &game->img.width, &game->img.height);
	game->img.border = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/border.xpm", &game->img.width, &game->img.height);
	game->img.img_collectible = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/collectible.xpm", &game->img.width, &game->img.height);
	game->img.img_exit[0] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/exit0.xpm", &game->img.width, &game->img.height);
	game->img.current_exit = game->img.img_exit[0];
	game->img.img_exit[1] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/exit1.xpm", &game->img.width, &game->img.height);
	game->img.img_idle[0] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/idle/idle0.xpm", &game->img.width, &game->img.height);
	game->img.img_idle[1] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/idle/idle1.xpm", &game->img.width, &game->img.height);
}