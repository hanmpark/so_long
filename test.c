/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:41:26 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/13 12:47:35 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/get_next_line.h"
#include "libft/includes/ft_printf.h"
#include <fcntl.h>

int	main()
{
	int		fd;
	char	**str;
	int		i;

	i = 0;
	fd = open("maps/easy.ber", O_RDONLY);
	str[i] = get_next_line(fd);
	while (str[i++])
	{
		str[i] = get_next_line(fd);
		ft_printf("%s", str[i]);
		free(str[i]);
	}
	return (0);
}