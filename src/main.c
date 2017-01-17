/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:52:10 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/03 21:48:38 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	min_size(char **tetros)
{
	int	i;
	int	size;

	i = 0;
	size = 2;
	while (tetros[i])
		i++;
	while (4 * i > size * size)
		size++;
	return (size);
}

static char	*read_and_get_string(char const *file)
{
	char	*in;
	int		fsize;

	fsize = ft_file_size(file);
	ft_validate_size(fsize);
	in = ft_file_string(file, fsize);
	if (!in)
	{
		ft_putendl("error");
		exit(0);
	}
	return (in);
}

static char	**string_to_alpha_tetros(char *in)
{
	char	**tetros;

	tetros = ft_split_tetros(in);
	free(in);
	ft_validate_tetros(tetros);
	ft_shove_top_left(tetros);
	ft_alpha_tetros(tetros);
	return (tetros);
}

static void	usage(void)
{
	ft_putendl("usage: ./fillit target_file");
}

int			main(int ac, char **av)
{
	char	*in;
	char	**tetros;
	char	*map;
	int		i;

	if (ac == 2)
	{
		in = read_and_get_string(av[1]);
		tetros = string_to_alpha_tetros(in);
		map = ft_fillit(ft_make_map(min_size(tetros)), tetros, 0, 0);
		ft_putstr(map);
		free(map);
		i = 0;
		while (tetros[i])
			i++;
		while (--i >= 0)
			free(tetros[i]);
		free(tetros);
	}
	else
		usage();
	return (0);
}
