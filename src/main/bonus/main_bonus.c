/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:22:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 09:54:23 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/game_bonus.h"
#include "../../../inc/parsing_bonus.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		ft_error(NULL, NULL, ERR_BER);
	map_init(argv[1], &game);
	game_init(&game);
	return (0);
}
