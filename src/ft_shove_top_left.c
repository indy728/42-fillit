/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shove_top_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 03:36:26 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/18 12:18:32 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	find_min_x(char *tetro)
{
	int	x;
	int i;

	x = 3;
	i = 0;
	while (tetro[i])
	{
		if (tetro[i] == '#' && x > i % 5)
			x = (i % 5);
		i++;
	}
	return (x);
}

static	int	find_min_y(char *tetro)
{
	int	y;
	int i;

	y = 3;
	i = 0;
	while (tetro[i])
	{
		if (tetro[i] == '#' && y > i / 5)
			y = (i / 5);
		i++;
	}
	return (y);
}

void		ft_shove_top_left(char **tetro)
{
	int x;
	int y;
	int i;
	int j;

	i = 0;
	while (tetro[i])
	{
		x = find_min_x(tetro[i]);
		y = find_min_y(tetro[i]);
		j = 0;
		while (tetro[i][j])
		{
			if (tetro[i][j] == '#')
			{
				tetro[i][j] = '.';
				tetro[i][j - (y * 5 + x)] = '#';
			}
			++j;
		}
		++i;
	}
}
