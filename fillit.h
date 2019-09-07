/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:42:35 by amargy            #+#    #+#             */
/*   Updated: 2019/09/01 15:52:21 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>

typedef	struct	s_struct
{
	int			x[4];
	int			y[4];
	int			height;
	int			width;
	char		letter;
	int			number;
}				t_struct;

int				valid(char *argv, int *f_count, t_struct *f_depot, int index);
int				input_field_valid(char *buff);
int				input_figure_valid(char *buff);
void			put_figure_in_struct(char *all_buff,
				t_struct *f_depot, int f_count);
void			put_figure_in_xy(int struct_index,
				char *buff, t_struct *f_depot);
int				move_in_out(int *coord_mas);
int				size_figure(int *coord_mas);
int				square_size(int f_count);
void			solution(t_struct *f_depot, int f_count, int square_size);
void			print_all(char map[17][17], int square_size);

#endif
