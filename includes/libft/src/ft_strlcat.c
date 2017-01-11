/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:09:38 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/07 23:27:07 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, char const *s2, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	j = 0;
	i = ft_strlen(s1);
	if (size > i)
		k = i;
	else
		k = size;
	while (s2[j] && i + 1 < size)
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (k + ft_strlen(s2));
}
