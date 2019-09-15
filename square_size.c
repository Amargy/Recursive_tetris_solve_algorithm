/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:28:07 by amargy            #+#    #+#             */
/*   Updated: 2019/09/01 14:43:13 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	square_size(int cells)
{
	int square_side;

	square_side = 0;
	while (square_side * square_side < cells)
	{
		square_side++;
	}
	return (square_side);
}
