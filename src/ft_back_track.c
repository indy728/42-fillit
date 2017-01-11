/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_track.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:26:14 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/28 17:27:43 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_back_track(char *map, char *tetro, char c)
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
