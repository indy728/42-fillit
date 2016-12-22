/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:52:10 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/21 16:41:44 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	char	*in;
	int fsize;
	char **tetros;
	char *map;

	if (ac != 2)
		return (0);
	fsize = ft_file_size(av[1]);
	ft_validate_size(fsize);
	in = ft_file_string(av[1], fsize);
	if (!in)
	{
		ft_putstr("could not allocate file string.\n");
		return(0);
	}
	ft_putstr(in);
	ft_putchar('\n');
	tetros = ft_split_tetros(in);	
	free(in);
	ft_validate_tetros(tetros);
	ft_shove_top_left(tetros);
	ft_alpha_tetros(tetros);
	int i = 0;
	map = ft_fillit(ft_make_map(2), tetros, 0, 0);
	ft_putstr(map);
	free(map);
	i = 0;
	while (tetros[i])
		i++;
	while (--i >= 0)
		free(tetros[i]);
	free(tetros);
	return (0);
}
