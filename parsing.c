/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/13 13:45:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

typedef struct	s_check
{
	int	coin;
	int	player;
	int	exit;
}	t_check;

void	clear_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}

int	check_map(char **map, t_check *check)
{
	int	i;
	int	k;
	int	xlen;

	k = 0;
	i = 0;
	xlen = ft_strlen(map[k]) - 1;
	/* check lines */
	while(map[k][i])
	{
		i = 0;
		if (k == 0)
		{
			ft_printf("%c", map[k][i]);
			if (map[k][i] != '1' && map[k][i] != '\n')
				return (0);
			i++;
		}
		k++;
	}
	return (1);
}

void	init_check(t_check *check)
{
	check->coin = 0;
	check->exit = 0;
	check->player = 0;
}

int	main(void)
{
	char	**map;
	t_check	*check;
	int		fd;
	int		i;

	fd = open("maps/easy.ber", O_RDONLY);
	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		ft_printf("%s", map[i]);
		if (!map[i])
			break ;
		i++;
	}
	ft_putchar_fd('\n', 1);
	close(fd);
	check = malloc(sizeof(t_check));
	init_check(check);
	if (!check_map(map, check))
	{
		ft_printf("map is in wrong format\n");
		return (-1);
	}
	clear_map(map);
	return (0);
}