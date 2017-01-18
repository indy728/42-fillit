/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 00:17:38 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/18 12:15:25 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tetro_next(char const *tetro, int i)
{
	if (tetro[i + 1] == '#')
		return (1);
	return (0);
}

static int	tetro_next_line(char const *tetro, int i)
{
	if (tetro[i + 5] == '#')
		return (1);
	return (0);
}

static int	tetro_prev(char const *tetro, int i)
{
	if (tetro[i - 1] == '#')
		return (1);
	return (0);
}

static int	tetro_prev_line(char const *tetro, int i)
{
	if (tetro[i - 5] == '#')
		return (1);
	return (0);
}

int			ft_is_tetro(char const *tetro)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tetro[i])
	{
		if (tetro[i] == '#' && i == 0)
			count += tetro_next(tetro, i) + tetro_next_line(tetro, i);
		else if (tetro[i] == '#' && i < 5)
			count += tetro_next(tetro, i) + tetro_next_line(tetro, i)
				+ tetro_prev(tetro, i);
		else if (tetro[i] == '#' && i == 18)
			count += tetro_prev(tetro, i) + tetro_prev_line(tetro, i);
		else if (tetro[i] == '#' && i > 14)
			count += tetro_next(tetro, i) + tetro_prev_line(tetro, i)
				+ tetro_prev(tetro, i);
		else if (tetro[i] == '#')
			count += tetro_next(tetro, i) + tetro_prev_line(tetro, i)
				+ tetro_prev(tetro, i) + tetro_next_line(tetro, i);
		i++;
	}
	if (count >= 6)
		return (1);
	return (0);
}
