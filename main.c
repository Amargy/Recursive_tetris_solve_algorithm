/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:27:36 by amargy            #+#    #+#             */
/*   Updated: 2019/09/01 15:53:20 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			f_count;
	t_struct	f_depot[26];
	int			square_side;
	int			index;

	index = 0;
	f_count = 0;
	if (argc == 2)
	{
		if (!(valid(argv[1], &f_count, f_depot, index)) || f_count == 0)
		{
			ft_putendl("error");
			return (0);
		}
		square_side = square_size(4 * f_count);
		solution(f_depot, f_count, square_side);
	}
	else
		ft_putendl("usage: ./fillit input_file");
	return (0);
}
