/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:22:06 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/08 09:31:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_error(char **map, char *str)
{
	ft_freetab(map);
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\033[0m", 2);
	exit (1);
}