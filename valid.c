/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:57:05 by amargy            #+#    #+#             */
/*   Updated: 2019/09/01 15:58:37 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		input_figure_valid(char *buff)
{
	int index;
	int coupling;

	index = 0;
	coupling = 0;
	while (buff[index])
	{
		if (buff[index] == '#')
		{
			if (buff[index + 1] == '#')
				coupling++;
			if (index != 0 && buff[index - 1] == '#')
				coupling++;
			if (index <= 13 && buff[index + 5] == '#')
				coupling++;
			if (index >= 5 && buff[index - 5] == '#')
				coupling++;
		}
		index++;
	}
	if (coupling == 6 || coupling == 8)
		return (1);
	return (0);
}

int		input_field_valid(char *buff)
{
	int	point;
	int grill;
	int slash_n;
	int index;

	point = 0;
	grill = 0;
	slash_n = 0;
	index = 0;
	if (buff[0] == '\n')
		return (0);
	while (buff[index])
	{
		if (buff[index] == '.')
			point++;
		if (buff[index] == '#')
			grill++;
		if (buff[index] == '\n')
			slash_n++;
		index++;
	}
	if (point == 12 && grill == 4 && (slash_n == 5 || slash_n == 4))
		return (1);
	return (0);
}

int		valid(char *argv, int *f_count, t_struct *f_depot, int index)
{
	int		ret;
	char	all_buff[546];
	int		fd;
	char	one_buff[22];

	if (!(fd = open(argv, O_RDONLY)) || fd < 0)
		return (0);
	ft_memset(all_buff, '\0', 546);
	if ((ret = read(fd, all_buff, 546)) <= 0)
		return (0);
	while (all_buff[index])
	{
		ft_strncpy(one_buff, &all_buff[index], 21);
		if (!(input_field_valid(one_buff)) || !(input_figure_valid(one_buff)))
			return (0);
		*f_count = *f_count + 1;
		index = index + 21;
	}
	if (one_buff[20] != '\0')
		return (0);
	put_figure_in_struct(all_buff, f_depot, *f_count);
	return (1);
}
