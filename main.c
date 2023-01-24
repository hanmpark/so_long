/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:22:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/24 16:31:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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
	if (!map || !*map)
	{
		free(mapi);
		ft_putstr_fd("Not okay\n", 2);
		system("leaks a.out");
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
	system("leaks a.out");
	return (0);
}
