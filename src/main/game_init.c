/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/08 14:36:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	ft_close(void)
{
	exit(0);
}

static t_win	new_window(void *mlx, int x, int y)
{
	t_win	win;

	win.id = mlx_new_window(mlx, x, y, "so_long");
	win.size.x = x;
	win.size.y = y;
	mlx_hook(win.id, 17, 0, *ft_close, 0);
	return (win);
}

// static int	ft_input(int key, void *param)
// {
// 	t_data *prog;

// 	prog = (t_data *)param;
// 	mlx_clear_window(prog->mlx, prog->win.id);
// 	if (key == 124)
// 		prog->sprite_pos.x += prog->sprite.size.x;
// }

static void	end(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		ft_freetab(data->map);
		mlx_destroy_image(data->mlx, data->sprite.img_floor);
		mlx_destroy_image(data->mlx, data->sprite.img_wall);
		mlx_destroy_window(data->mlx, data->win.id);
	}
	free(data->mlx);
	exit(0);
}

static void	print_img(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win.id, img, game->sprite.width * x, game->sprite.height * y);
}

void	print_background(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			print_img(game, game->sprite.img_floor, j, i);
			if (game->map[i][j] == '1')
				print_img(game, game->sprite.img_wall, j, i);
			j++;
		}
		i++;
	}
}

int	render(t_data *game)
{
	print_background(game);
	return (0);
}

void	game_init(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_freetab(game->map);
		exit(1);
	}
	assign_texture(game);
	game->win = new_window(game->mlx, game->sprite.width * game->content.size.x, game->sprite.height * game->content.size.y);
	mlx_loop_hook(game->mlx, &render, game);
	// mlx_put_image_to_window(game->mlx, game->win.id, game->sprite.img_wall, 0, 0);
	// print_img(game, game->sprite.img_floor, 0, 0);
	// prog.sprite = new_sprite(prog.mlx, "../../sprites/ground.xpm");
	// prog.sprite_pos.x = mapi->player.x * 16;
	// prog.sprite_pos.y = mapi->player.y * 16;
	// mlx_put_image_to_window(prog.mlx, prog.win.id, prog.sprite.id, prog.sprite_pos.x, prog.sprite_pos.y);
	// mlx_key_hook(prog.win.id, *ft_input, &prog);
	mlx_loop(game->mlx);
	end(game);
}
