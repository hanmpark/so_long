/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:37:47 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/11 00:40:26 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_list	*load_dir(char *path)
{
	t_list	*img;
	char	**str;
	int		i;

	str = malloc(5 * sizeof(char *));
	if (!str)
		return (0);
	*str = ft_strdup(path);
	ft_printf("%s\n", *str);
	img = ft_lstnew(*str);
	i = 1;
	while (*str)
	{
		str++;
		*str = ft_strdup(path);
		*str = ft_memset(str + 23, i, 1);
		ft_printf("%s\n", *str);
		ft_lstadd_back(&img, ft_lstnew(*str));
		i++;
	}
	return (img);
}

int	main(void)
{
	t_list	*test;

	test = load_dir("./sprites/dir/down/down0.xpm");
	if (!test)
		ft_printf("Bruh\n");
	return (0);
}