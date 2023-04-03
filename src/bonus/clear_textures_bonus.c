/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:59:40 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 16:06:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

static void	clear_list(t_list **list, t_data *g)
{
	t_list	*current_list;
	t_list	*next;

	current_list = *list;
	while (current_list != NULL)
	{
		next = current_list->next;
		mlx_destroy_image(g->mlx, current_list->content);
		free(current_list);
		current_list = NULL;
		current_list = next;
	}
	*list = NULL;
}

static void	clear_environment(t_data *g)
{
	mlx_destroy_image(g->mlx, g->img.wall);
	mlx_destroy_image(g->mlx, g->img.floor[0]);
	mlx_destroy_image(g->mlx, g->img.floor[1]);
	mlx_destroy_image(g->mlx, g->img.floor[2]);
	mlx_destroy_image(g->mlx, g->img.exit[0]);
	mlx_destroy_image(g->mlx, g->img.exit[1]);
	mlx_destroy_image(g->mlx, g->img.border[0]);
	mlx_destroy_image(g->mlx, g->img.border[1]);
	mlx_destroy_image(g->mlx, g->img.border[2]);
}

static void	clear_numbers(t_data *g)
{
	mlx_destroy_image(g->mlx, g->img.number[0]);
	mlx_destroy_image(g->mlx, g->img.number[1]);
	mlx_destroy_image(g->mlx, g->img.number[2]);
	mlx_destroy_image(g->mlx, g->img.number[3]);
	mlx_destroy_image(g->mlx, g->img.number[4]);
	mlx_destroy_image(g->mlx, g->img.number[5]);
	mlx_destroy_image(g->mlx, g->img.number[6]);
	mlx_destroy_image(g->mlx, g->img.number[7]);
	mlx_destroy_image(g->mlx, g->img.number[8]);
	mlx_destroy_image(g->mlx, g->img.number[9]);
}

void	clear_textures(t_data *g)
{
	clear_list(&g->img.left, g);
	clear_list(&g->img.right, g);
	clear_list(&g->img.down, g);
	clear_list(&g->img.up, g);
	clear_list(&g->img.mob, g);
	clear_list(&g->img.collectible, g);
	mlx_destroy_image(g->mlx, g->img.dead);
	clear_environment(g);
	clear_numbers(g);
}
