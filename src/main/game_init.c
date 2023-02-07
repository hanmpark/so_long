/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/07 16:23:47 by hanmpark         ###   ########.fr       */
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
	mlx_hook(win.id, 27, 0, *ft_close, 0);
	return (win);
}

static t_img	new_sprite(void *mlx, char *path)
{
	t_img	sprite;

	sprite.id = mlx_xpm_file_to_image(mlx, path, &sprite.size.x, &sprite.size.y);
	sprite.addr = mlx_get_data_addr(sprite.id, &sprite.bbp, &sprite.line_len, &sprite.endian);
	return (sprite);
}

// static int	ft_input(int key, void *param)
// {
// 	t_data *prog;

// 	prog = (t_data *)param;
// 	mlx_clear_window(prog->mlx, prog->win.id);
// 	if (key == 124)
// 		prog->sprite_pos.x += prog->sprite.size.x;
// }

void	game_init(char **map, t_parse *mapi)
{
	t_data	prog;
	int		i;
	int		j;

	prog.mlx = mlx_init();
	prog.win = new_window(prog.mlx, mapi->size.x * 16, mapi->size.y * 16);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			prog.sprite = new_sprite(prog.mlx, "../../sprites/ground.xpm");
			mlx_put_image_to_window(prog.mlx, prog.win.id, prog.sprite.id, j * 16, i * 16);
		}
	}
	// prog.sprite = new_sprite(prog.mlx, "../../sprites/ground.xpm");
	// prog.sprite_pos.x = mapi->player.x * 16;
	// prog.sprite_pos.y = mapi->player.y * 16;
	// mlx_put_image_to_window(prog.mlx, prog.win.id, prog.sprite.id, prog.sprite_pos.x, prog.sprite_pos.y);
	// mlx_key_hook(prog.win.id, *ft_input, &prog);
	mlx_loop(prog.mlx);
}
