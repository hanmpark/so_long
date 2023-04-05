/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:02:53 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 18:34:40 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_BONUS_H
# define MOVE_BONUS_H

# define MOVE_ENEMY 1
# define STILL_ENEMY 0
# define LEFT 1
# define RIGHT 2
# define STATIC 0

void	move_player(t_data *game);
void	move_enemy(t_data *game);
void	move_dir(int x, int y, t_data *game);

#endif