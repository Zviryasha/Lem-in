/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:40:37 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/07 17:14:57 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	st_ed(int *yij, char **tse, char **s)
{
	yij[0] = 0;
	yij[1] = 0;
	yij[2] = 0;
	while (s[yij[0]] != NULL)
		yij[0]++;
	while (ft_strcmp(s[yij[1]], tse[1]) != 0)
		yij[1]++;
	while (ft_strcmp(s[yij[2]], tse[2]) != 0)
		yij[2]++;
}

int		*algo(int *yij, int **c, int *a, int *k)
{
	int l;
	int max;

	*k = check_empty(yij[1], yij[2], c, yij[0]);
	if (*k == -1)
		return (a);
	*k = yij[1];
	l = 0;
	while (*k != yij[2] && *k != -1)
	{
		*k = find_x(c, *k, yij[0], yij[2]);
		a[l] = *k;
		if (*k == -1)
		{
			max = max_in(c, yij[0]);
			*k = a[l - 2];
			if (*k == yij[1])
				return (a);
			cleaner(c, yij[0], a[l - 2], a[l - 1]);
			popo(c, a, &l, max);
		}
		l++;
	}
	a[l] = -30;
	return (a);
}

void	popo(int **c, int *a, int *l, int max)
{
	c[a[*l - 2]][a[*l - 1]] = max;
	c[a[*l - 1]][a[*l - 2]] = max;
	*l = *l - 2;
}
