/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_figure_in_structure.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:55:08 by amargy            #+#    #+#             */
/*   Updated: 2019/09/01 15:28:28 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		f_size(int *coord_mas)
{
	int	index;
	int	max;

	index = 0;
	max = 0;
	while (index < 4)
	{
		if (max < coord_mas[index])
			max = coord_mas[index];
		index++;
	}
	return (++max);
}

int		move_in_out(int *coord_mas)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		if (coord_mas[index] == 0)
			return (0);
		index++;
	}
	while (--index >= 0)
	{
		coord_mas[index]--;
	}
	return (move_in_out(coord_mas));
}

void	put_figure_in_xy(int struct_index, char *buff, t_struct *f_depot)
{
	int xy_index;
	int buff_index;

	buff_index = 0;
	xy_index = 0;
	while (buff[buff_index])
	{
		if (buff[buff_index] == '#')
		{
			f_depot[struct_index].x[xy_index] = buff_index % 5;
			f_depot[struct_index].y[xy_index] = buff_index / 5;
			xy_index++;
		}
		buff_index++;
	}
}

void	put_figure_in_struct(char *all_buff, t_struct *f_depot, int f_count)
{
	int		struct_index;
	int		buff_index;
	char	one_buff[22];
	char	let;

	buff_index = 0;
	struct_index = 0;
	let = 'A';
	while (buff_index != f_count * 21)
	{
		ft_strncpy(one_buff, &all_buff[buff_index], 21);
		one_buff[21] = '\0';
		put_figure_in_xy(struct_index, one_buff, f_depot);
		move_in_out(f_depot[struct_index].x);
		move_in_out(f_depot[struct_index].y);
		f_depot[struct_index].width = f_size(f_depot[struct_index].x);
		f_depot[struct_index].height = f_size(f_depot[struct_index].y);
		f_depot[struct_index].letter = let++;
		struct_index++;
		buff_index = buff_index + 21;
		f_depot[struct_index - 1].number = struct_index;
	}
}
