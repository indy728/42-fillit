/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_tetros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 23:47:15 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/18 11:54:02 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_alpha_tetros(char **tetros)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tetros[i])
	{
		j = 0;
		while (tetros[i][j])
		{
			if (tetros[i][j] == '#')
				tetros[i][j] = i + 'A';
			j++;
		}
		i++;
	}
}
