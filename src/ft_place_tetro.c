/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:31:59 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/18 12:17:29 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place_tetro(char *map, char *tetro, int i, int size)
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
			++k;
			if (*tetro != '.' && *(tetro + 1) != *tetro)
			{
				while (*tetro != '\n')
					++tetro;
				while ((i + 1) % (size + 1) != n % (size + 1))
					++i;
			}
		}
		++i;
		++tetro;
	}
}
