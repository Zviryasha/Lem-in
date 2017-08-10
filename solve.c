/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:25:31 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/08 12:15:07 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*solve(char *rooms, int **c, char **tse)
{
	char	**s;
	int		k;
	int		*a;
	int		yij[3];

	a = (int *)malloc(sizeof(int) * 300);
	s = ft_strsplit(rooms, ' ');
	st_ed(yij, tse, s);
	a = algo(yij, c, a, &k);
	if (k == -1 || k == yij[1])
		a[0] = -1;
	k = -1;
	while (s[++k] != NULL)
		free(s[k]);
	free(s);
	return (a);
}

int		find_x(int **c, int p, int y, int j)
{
	int i;
	int k;
	int max;

	k = -1;
	i = 0;
	if (c[p][j] == 1)
		return (j);
	max = max_in(c, y);
	while (i < y)
	{
		if (c[p][i] == 1 && k == -1)
			k = i;
		if (c[p][i] == 1)
		{
			c[p][i] = p + 2;
			c[i][p] = p + 2;
		}
		i++;
	}
	return (k);
}

void	cleaner(int **c, int y, int a1, int a2)
{
	int j;
	int max;

	max = max_in(c, y);
	j = -1;
	while (++j < y)
	{
		if (c[a1][j] == max)
			c[a1][j] = 1;
	}
	j = -1;
	while (++j < y)
	{
		if (c[a2][j] == max)
			c[a2][j] = 1;
	}
	j = -1;
	while (++j < y)
	{
		if (c[j][a1] == max)
			c[j][a1] = 1;
		if (c[j][a2] == max)
			c[j][a2] = 1;
	}
}

int		max_in(int **c, int y)
{
	int i;
	int j;
	int max;

	max = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < y)
		{
			if (max < c[i][j])
				max = c[i][j];
			j++;
		}
		i++;
	}
	return (max);
}
