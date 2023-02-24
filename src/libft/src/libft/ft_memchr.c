/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:36:26 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/24 09:21:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	ch;
	char	*str;
	int		i;

	ch = (char)c;
	i = 0;
	str = (char *)s;
	while (n--)
	{
		if (str[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
