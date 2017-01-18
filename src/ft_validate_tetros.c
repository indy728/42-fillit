/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_tetros.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:52:53 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/18 12:31:01 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	exit_zero(void)
{
	ft_putendl("error");
	exit(0);
}

void			ft_validate_tetros(char **str)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_strlen(str[i]) != 20)
			exit_zero();
		j = 0;
		k = 0;
		while (str[i][j])
		{
			if ((j + 1) % 5 == 0 && str[i][j] != '\n')
				exit_zero();
			if ((j + 1) % 5 != 0 && str[i][j] != '.' && str[i][j] != '#')
				exit_zero();
			if (str[i][j] == '#')
				++k;
			++j;
		}
		if (k != 4 || !ft_is_tetro(str[i]))
			exit_zero();
		++i;
	}
}
