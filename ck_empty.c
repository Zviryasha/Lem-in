/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:59:11 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/09 05:48:06 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_empty(int o, int p, int **c, int y)
{
	int i;
	int count;
	int op;

	op = 0;
	count = 0;
	i = 0;
	while (i != y)
	{
		if (c[o][i] == 1)
			count++;
		if (c[p][i] == 1)
			op++;
		i++;
	}
	if ((count == 0 || op == 0) && y >= 4)
		return (-1);
	if ((is_ed(o, p, c, y) == -1) && y >= 4)
		return (-1);
	else
		return (0);
}

int		is_ed(int o, int p, int **c, int y)
{
	int i;
	int cu;
	int ou;

	i = -1;
	while (++i != y)
	{
		if (c[o][i] == 1)
			cu = i;
		if (c[p][i] == 1)
			ou = i;
	}
	if (iyy(ou, cu, c, y) == -1)
		return (-1);
	else
		return (0);
}

int		iyy(int ou, int cu, int **c, int y)
{
	int count;
	int op;
	int i;

	count = 0;
	op = 0;
	i = -1;
	while (++i != y)
	{
		if (c[cu][i] == 1)
			count++;
		if (c[ou][i] == 1)
			op++;
	}
	if (count == 1 || op == 1)
		return (-1);
	else
		return (0);
}
