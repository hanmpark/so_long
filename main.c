/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:22:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/21 00:49:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_parse	*mapinfo;

	if (argc != 2 || !argv[1])
		return (1);
	mapinfo = NULL;
	if (!ft_allocptr(mapinfo, sizeof(t_parse)))
		return (1);
	map = init_map(argv[1], mapinfo);
	if (!map)
	{
		ft_putstr_fd("Not okay\n", 2);
		return (1);
	}
	/* print out the map */
	int	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	ft_printf("--------------------------------\n");
	ft_printf("size = %d, %d\n", mapinfo->size.x, mapinfo->size.y);
	ft_printf("player pos = %d, %d\n", mapinfo->player.x, mapinfo->player.y);
	ft_printf("collectible = %d\n", mapinfo->collectible);
	ft_printf("exit = %d\n", mapinfo->exit);
	ft_printf("--------------------------------\n");
	/* ----------------- */
	ft_printf("Edges ok\n");
	return (0);
}
