/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:30:08 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/28 17:37:54 by kmurray          ###   ########.fr       */
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
int					ft_vertical_fit(char *tetro, int n, int size);
void				ft_place_tetro(char *map, char *tetro, int i, int size);
int					ft_back_track(char *map, char *tetro, char c);
int					ft_does_it_fit(char *map, char *tetro, int i, int size);
char				*ft_fillit(char *map, char **tetros, int i, int j);

#endif
