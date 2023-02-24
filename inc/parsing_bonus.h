/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:46:00 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 09:18:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "../src/libft/inc/get_next_line.h"

# define MAP_OKAY 1
# define MAP_WRONG 0

# define ERR_MALLOC "Error\nMalloc failed\n"
# define ERR_FORMAT "Error\nFormat error\n"
# define ERR_WALLS "Error\nFound an element different from '1' for wall(s)\n"
# define ERR_ELEMENTS "Error\nWrong number of elements\n"
# define ERR_IMPOSSIBLE "Error\nYour map is impossible !\n"
# define ERR_CASE "Error\nSomething wrong with case(s)\n"
# define ERR_BER "Error\n.ber file does not exist\n"

void	map_init(const char *file, t_data *game);
void	check_edges(char **map, t_data *game);
void	check_content(char **map, t_data *game);

#endif