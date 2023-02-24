/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:22:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 16:33:48 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/game.h"
#include "../../../inc/parsing.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		ft_error(NULL, NULL, ERR_BER);
	map_init(argv[1], &game);
	game_init(&game);
	return (0);
}
