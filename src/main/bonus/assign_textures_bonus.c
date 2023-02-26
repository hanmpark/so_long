/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:14:22 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/26 16:00:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/game_bonus.h"

static t_list	*load_sprites(char *path, char times, t_data *game)
{
	t_list	*img;
	int		set;
	char	*str;
	char	number;

	str = ft_strdup(path);
	img = ft_lstnew(mlx_xpm_file_to_image(game->mlx, str, \
		&game->img.width, &game->img.height));
	number = '1';
	set = 0;
	while (str && str[set] != '0')
		set++;
	while (number < times)
	{
		str[set] == number;
		ft_lstadd_back(&img, ft_lstnew(mlx_xpm_file_to_image(game->mlx, str, \
			&game->img.width, &game->img.height)));
		number++;
	}
	free(str);
	return (img);
}

static void	assign_sprites(t_data *game)
{
	t_img	*img;

	img = &game->img;
	img->down = load_sprites("./img/player/dir/down/down0.xpm", '4', game);
	img->up = load_sprites("./img/player/dir/up/up0.xpm", '4', game);
	img->left = load_sprites("./img/player/dir/left/left0.xpm", '4', game);
	img->right = load_sprites("./img/player/dir/right/right0.xpm", '4', game);
	img->current = game->img.down;
	img->current_back = game->img.down;
	img->dead = mlx_xpm_file_to_image(game->mlx, \
		"./img/player/dead.xpm", &game->img.width, &game->img.height);
	img->mob = load_sprites("./img/mob/mob0.xpm", '8', game);
	img->mob_back = game->img.mob;
	img->collectible = load_sprites("./img/collectible/coin0.xpm", '7', game);
	img->collectible_back = game->img.collectible;
}

static void	assign_environment(t_data *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/wall.xpm", &game->img.width, &game->img.height);
	game->img.floor[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/ground.xpm", &game->img.width, &game->img.height);
	game->img.floor[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/ground1.xpm", &game->img.width, &game->img.height);
	game->img.floor[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/ground2.xpm", &game->img.width, &game->img.height);
	game->img.exit[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/exit0.xpm", &game->img.width, &game->img.height);
	game->img.exit[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/exit1.xpm", &game->img.width, &game->img.height);
	game->img.border[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/border/border.xpm", &game->img.width, &game->img.height);
	game->img.border[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/border/border_go.xpm", &game->img.width, &game->img.height);
	game->img.border[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/border/border_lvl.xpm", &game->img.width, &game->img.height);
}

static void	assign_numbers(t_data *game)
{
	game->img.number[0] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/0.xpm", &game->img.width, &game->img.height);
	game->img.number[1] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/1.xpm", &game->img.width, &game->img.height);
	game->img.number[2] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/2.xpm", &game->img.width, &game->img.height);
	game->img.number[3] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/3.xpm", &game->img.width, &game->img.height);
	game->img.number[4] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/4.xpm", &game->img.width, &game->img.height);
	game->img.number[5] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/5.xpm", &game->img.width, &game->img.height);
	game->img.number[6] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/6.xpm", &game->img.width, &game->img.height);
	game->img.number[7] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/7.xpm", &game->img.width, &game->img.height);
	game->img.number[8] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/8.xpm", &game->img.width, &game->img.height);
	game->img.number[9] = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/9.xpm", &game->img.width, &game->img.height);
}

void	assign_textures(t_data *game)
{
	assign_sprites(game);
	assign_environment(game);
	assign_numbers(game);
}
