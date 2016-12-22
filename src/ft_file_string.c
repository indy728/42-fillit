/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 23:08:57 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/21 14:33:34 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_file_string(char const *path, int size)
{
	int		fd;
	int		bytes_read;
	char	*in;
	char	buf[BUF_SIZE];

	in = (char *)malloc(sizeof(char) * (size + 1));
	if (!in)
		return (NULL);
 	in[size] = '\0';
	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((bytes_read = read(fd, buf, BUF_SIZE)))
	{
		in[size] = buf[0];
		size++;
	}
	if(close(fd) == -1)
		return (NULL);
	return (in);
}
