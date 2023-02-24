/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:05:15 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 09:21:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

static int	maplen(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

char	**ft_mapdup(char **map)
{
	char	**res;
	int		i;

	i = -1;
	res = malloc((maplen(map) + 1) * sizeof(char *));
	if (!res)
		return (0);
	while (map && map[++i])
		res[i] = ft_strdup(map[i]);
	res[i] = 0;
	return (res);
}