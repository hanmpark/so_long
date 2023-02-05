/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:22:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/05 21:14:02 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_parse	*mapi;

	if (argc != 2 || !argv[1])
		return (1);
	mapi = malloc(sizeof(t_parse));
	if (!mapi)
		return (1);
	map = map_init(argv[1], mapi);
	if (!map)
	{
		free(mapi);
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
	ft_printf("size = %d, %d\n", mapi->size.x, mapi->size.y);
	ft_printf("player pos = %d, %d\n", mapi->player.x, mapi->player.y);
	ft_printf("collectible = %d\n", mapi->collectible);
	ft_printf("exit = %d\n", mapi->exit);
	ft_printf("--------------------------------\n");
	/* ----------------- */
	ft_printf("Edges ok\n");
	free(mapi);
	ft_freetab(map);
	system("leaks so_long");
	return (0);
}
