/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:15:17 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/06 19:59:15 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	map_size(char *map)
{
	int size;

	size = 0;
	while (map[size] != '\n')
		size++;
	return (size);
}

char		*ft_fillit(char *map, char **tetros, int i, int j)
{
	int size;

	size = map_size(map);
	while (tetros[j])
	{
		if (!ft_vertical_fit(tetros[j], i, size))
		{
			if (j == 0)
			{
				free(map);
				map = ft_make_map(++size);
				i = 0;
			}
			else
			{
				--j;
				i = ft_back_track(map, tetros[j], j + 'A');
			}
		}
		else if (!ft_does_it_fit(map, tetros[j], i, size))
		{
			i++;
			while (map[i] != '.' && ft_isalpha(*(tetros[j])) &&
					ft_vertical_fit(tetros[j], i, size))
				i++;
		}
		else
		{
			ft_place_tetro(map, tetros[j], i, size);
			i = 0;
			++j;
		}
	}
	return (map);
}
