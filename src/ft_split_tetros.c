/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tetros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 02:01:08 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/18 12:27:35 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		count_words(char const *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || !str[i + 1]))
			++count;
		++i;
	}
	return (count);
}

static	int		wordlen(char const *str, size_t i)
{
	int	count;

	count = 0;
	while (str[i])
	{
		++count;
		if (str[i] == '\n' && (str[i + 1] == '\n' || !str[i + 1]))
			break ;
		++i;
	}
	return (count);
}

static	void	newstring(char const *str, char *new, size_t wl, size_t n)
{
	size_t	i;

	i = 0;
	while (i < wl)
		new[i++] = str[n++];
	new[i] = '\0';
}

char			**ft_split_tetros(char const *str)
{
	int		i;
	size_t	wl;
	size_t	n;
	char	**tetros;

	i = 0;
	n = 0;
	if (!str)
		return (NULL);
	if (!(tetros = (char **)malloc(sizeof(tetros) * (count_words(str) + 1))))
		return (NULL);
	while (i < count_words(str))
	{
		while (str[n] == '\n')
			++n;
		wl = wordlen(str, n);
		if (!(tetros[i] = (char *)malloc(wl + 1)))
			return (NULL);
		newstring(str, tetros[i], wl, n);
		n += wl;
		++i;
	}
	tetros[i] = NULL;
	return (tetros);
}
