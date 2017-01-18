/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 23:08:57 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/18 12:27:47 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_file_string(char const *path, int size)
{
	int		fd;
	int		bytes_read;
	char	*in;
	char	buf[BUF_SIZE];

	if (!(in = (char *)malloc(size + 1)))
		return (NULL);
	in[size] = '\0';
	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((bytes_read = read(fd, buf, BUF_SIZE)))
		in[size++] = buf[0];
	if (close(fd) == -1)
		return (NULL);
	return (in);
}
