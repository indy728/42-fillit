/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 01:57:16 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/21 14:34:03 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_make_map(int size)
{
	char	*map;
	int		i;

	map = (char *)malloc(size * (size + 1) + 1);
	map[size * (size + 1)] = '\0';
	i = 0;
	while (i < size * (size + 1))
	{
		if (i % (size + 1) == size)
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	return (map);
}
