/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_does_it_fit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:26:47 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/28 17:27:36 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_does_it_fit(char *map, char *tetro, int i, int size)
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
