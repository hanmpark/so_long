/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:22:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/07 07:47:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
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
	game_init(map, mapi);
	free(mapi);
	ft_freetab(map);
	return (0);
}
