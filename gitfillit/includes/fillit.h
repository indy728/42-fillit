/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:30:08 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/21 16:38:51 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 1

void				ft_validate_tetros(char **str);
void				ft_validate_size(int file_size);
int					ft_file_size(char const *path);
char				**ft_split_tetros(char const *str);
char				*ft_file_string(char const *path, int size);
void				ft_alpha_tetros(char **tetros);
int					ft_is_tetro(char const *tetro);
void				ft_shove_top_left(char **tetro);
char				*ft_make_map(int size);
char				*ft_fillit(char *map, char **tetros, int i, int j);

#endif
