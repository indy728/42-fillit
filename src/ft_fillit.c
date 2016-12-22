/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:15:17 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/21 16:44:32 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static	int	map_size(char *map)
{
	int size;

	size = 0;
	while (map[size] != '\n')
	{
		size++;
	}
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
	printf("y_size \n%s tetro %d i %d size\n", tetro, i, size);
	if (i-- / (5) + n / (size + 1)  + 1 > size)
		return (0);
	return (1);
}

static	int	tetros_xsize(char *tetro, int size)
{
	int k;
	int max;
	int i;
	
	k = 0;
	max = 0;
	i = 0;
	printf("tetros xsize\n");
	while (k < 4)
	{
		if (tetro[i] != '.' && tetro[i] != '\n')
		{
			if (i % 5 > max)
				max = i % 5;
			k++;
		}
		i++;
	}
	if (max + 1 > size)
		return (0);
	return (1);
}

static	int	back_track(char *map, char c)
{
	int k;
	int i;
	int n;

	k = 0;
	i = 0;
	printf("back_track\n");
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
	return (n + 1);
}

static	int	tetros_fit(char *map, char *tetro, int i, int size)
{
	int k;
	int n;

	n = i;
	k = 0;
	printf("%d i, tetros_fit\n", i);
	while (k < 4)
	{
		if (*tetro != '.' && *tetro != '\n' && map[i] == '.')
		{
			k++;
			if (*tetro != '.' && *(tetro + 1) != *tetro)
			{
				while (*tetro != '\n')
					tetro++;
				while ((i + 1) % (size + 1) != n % (size + 1))
					i++;
			}
		}
		else if (*tetro != '.' && *tetro != '\n' && map[i] != '.')
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
	printf("place_tetro\n");
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
	ft_putstr(map);
	if (!tetros[j])
		return (map);
	else if (size < 4 && (!tetros_ysize(tetros[j], 0, size) || !tetros_xsize(tetros[j], size)))
	{
		printf("2!\n");
		free(map);
		return (ft_fillit(ft_make_map(size + 1), tetros, 0, 0));
	}
	else if(!tetros_ysize(tetros[j], i, size))
	{
		if (j == 0)
		{
			printf("2!\n");
			free(map);
			return (ft_fillit(ft_make_map(size + 1), tetros, 0, 0));
		}
		else
		{
			printf("3!\n");
			i = back_track(map, (j - 1) + 'A');
			return (ft_fillit(map, tetros, i, j - 1));
		}
	}
	else if (!tetros_fit(map, tetros[j], i, size))
	{
		printf("4!\n");
		i++;
		while (map[i] != '.' && ft_isalpha(*(tetros[j])) && tetros_ysize(tetros[j], i, size))
			i++;
		return (ft_fillit(map, tetros, i, j));
	}
	else
	{
		printf("5!\n");
		place_tetro(map, tetros[j], i, size);
		return (ft_fillit(map, tetros, 0, j + 1));
	}
}
