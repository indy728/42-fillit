/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:47:22 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/03 21:34:08 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_file_size(char const *path)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		k;
	int		bytes_read;

	k = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	while ((bytes_read = read(fd, buf, BUF_SIZE)))
		k = k + bytes_read;
	if (close(fd) == -1)
		return (1);
	return (k);
}
