/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:15:17 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/11 19:09:27 by kmurray          ###   ########.fr       */
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

int			available_space(char *map, char *tetro, int i, int size)
{
	int gaps;

	gaps = 0;
	while (!ft_isalpha(tetro[gaps]))
		++gaps;
	while (map[i + gaps] != '.' && ft_vertical_fit(tetro, i, size))
		++i;
	return (i);
}

char		*new_map(char *map, int *i, int *size)
{
	free(map);
	map = ft_make_map(++*size);
	*i = 0;
	return (map);
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
				map = new_map(map, &i, &size);
			else
			{
				--j;
				i = ft_back_track(map, tetros[j], j + 'A');
				i = available_space(map, tetros[j], ++i, size);
			}
		}
		else if (!ft_does_it_fit(map, tetros[j], i, size))
			i = available_space(map, tetros[j], ++i, size);
		else
		{
			ft_place_tetro(map, tetros[j], i, size);
			i = available_space(map, tetros[j++], 0, size);
		}
	}
	return (map);
}
