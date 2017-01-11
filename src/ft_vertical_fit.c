/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_fit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:24:23 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/28 17:36:06 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_vertical_fit(char *tetro, int n, int size)
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
