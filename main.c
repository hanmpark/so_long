/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:22:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/15 12:08:04 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_parse	*mapinfo;
	int		i = 0;

	if (argc != 2 || !argv[1])
		return (-1);
	mapinfo = malloc(sizeof(t_parse));
	if (!mapinfo)
		return (-1);
	map = init_map(argv[1], mapinfo);
	/* print out the map */
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	/* ----------------- */
	if (!check_map((const char **)map, argv[1], mapinfo))
	{
		ft_printf("Edges of the map are not good...\n");
		return (-1);
	}
	ft_printf("Map is okay for edges...\n");
	return (0);
}
