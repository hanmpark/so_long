/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestr_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:05:24 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 16:06:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestr_array(char **str_array)
{
	int	i;

	i = 0;
	if (str_array)
	{
		while (str_array && str_array[i])
		{
			free(str_array[i]);
			i++;
		}
		free(str_array);
	}
}
