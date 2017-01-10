/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:15:17 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/22 15:31:04 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static	int	map_size(char *map)
{
	int size;

	size = 0;
	while (map[size] != '\n')
		size++;
	return (size);
}

static	int	tetros_ysize(char *tetro, int n, int size)
{
	int	k;
	int i;

	k = 0;
	i = 0;
	while (k < 4)
	{
		if (tetro[i] != '.' && tetro[i] != '\n')
			k++;
		i++;
	}
	if ((i - 1) / (5) + n / (size + 1) + 1 > size)
		return (0);
	return (1);
}

static	int	back_track(char *map, char *tetro, char c)
{
	int k;
	int i;
	int n;

	k = 0;
	i = 0;
	while (k < 4)
	{
		if (map[i] == c)
		{
			if (k == 0)
				n = i;
			map[i] = '.';
			k++;
		}
		i++;
	}
	i = 0;
	while (!ft_isalpha(tetro[i]))
		i++;
	return (n - i + 1);
}

static	int	tetros_fit(char *map, char *tetro, int i, int size)
{
	int k;
	int n;

	n = i % (size + 1);
	k = 0;
	while (k < 4)
	{
		if (ft_isalpha(*tetro) && map[i] == '.')
		{
			k++;
			if (*(tetro + 1) != *tetro)
			{
				while (*tetro != '\n')
					tetro++;
				while ((i + 1) % (size + 1) != n)
					i++;
			}
		}
		else if (ft_isalpha(*tetro) && map[i] != '.')
			return (0);
		i++;
		tetro++;
	}
	return (1);
}

static	void	place_tetro(char *map, char *tetro, int i, int size)
{
	int k;
	int n;

	n = i;
	k = 0;
	while (k < 4)
	{
		if (*tetro != '.' && *tetro != '\n')
		{
			map[i] = *tetro;
			k++;
			if (*tetro != '.' && *(tetro + 1) != *tetro)
			{
				while (*tetro != '\n')
					tetro++;
				while ((i + 1) % (size + 1) != n % (size + 1))
					i++;
			}
		}
		i++;
		tetro++;
	}
}

char		*ft_fillit(char *map, char **tetros, int i, int j)
{
	int size;
	
	size = map_size(map);
	if (!tetros[j])
		return (map);
	else if(!tetros_ysize(tetros[j], i, size))
	{
		if (j == 0)
		{
			free(map);
			return (ft_fillit(ft_make_map(size + 1), tetros, 0, 0));
		}
		else
		{
			i = back_track(map, tetros[j - 1], (j - 1) + 'A');
			return (ft_fillit(map, tetros, i, j - 1));
		}
	}
	else if (!tetros_fit(map, tetros[j], i, size))
	{
		i++;
		while (map[i] != '.' && ft_isalpha(*(tetros[j])) && tetros_ysize(tetros[j], i, size))
			i++;
		return (ft_fillit(map, tetros, i, j));
	}
	else
	{
		place_tetro(map, tetros[j], i, size);
		return (ft_fillit(map, tetros, 0, j + 1));
	}
}
