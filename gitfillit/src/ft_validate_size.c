/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:38:20 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/21 14:37:06 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_validate_size(int file_size)
{
	if ((file_size != 20 && (file_size - 20) % 21 != 0) || file_size < 20)
	{
		ft_putstr("error\n");
		exit (0);
	}
}