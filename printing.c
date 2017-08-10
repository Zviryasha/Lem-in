/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 11:29:38 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/09 07:32:20 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pr(int *a, char *rooms, char *number)
{
	char	**t;
	int		**p;
	int		k;
	int		max;

	t = ft_strsplit(rooms, ' ');
	max = is_max(a, my_atoi(number));
	p = (int **)malloc(sizeof(int *) * my_atoi(number));
	k = -1;
	while (++k != max)
		p[k] = (int *)malloc(sizeof(int) * max * 2);
	pr2(p, max, a, my_atoi(number));
	print(max, number, t, p);
	free(a);
	k = -1;
	while (t[++k] != NULL)
		free(t[k]);
	free(t);
	k = -1;
	max = my_atoi(number);
	while (++k != max)
		free(p[k]);
	free(p);
}

void	print(int max, char *number, char **t, int **p)
{
	int j;
	int k;
	int c;

	j = -1;
	while (++j != (max * 2))
	{
		k = 0;
		c = 0;
		while (k != my_atoi(number))
		{
			if (p[k][j] != -1)
			{
				ft_putchar_g('L');
				ft_putnbr(k + 1);
				ft_putchar('-');
				ft_putstr_m(t[p[k][j]]);
				ft_putchar(' ');
				c++;
			}
			k++;
		}
		if (c != 0)
			ft_putchar('\n');
	}
}

int		is_max(int *a, int num)
{
	int i;
	int max;

	i = 0;
	while (a[i] != -30)
		i++;
	if (num < i)
		max = i;
	else
		max = num;
	return (max);
}

void	pr2(int **p, int max, int *a, int num)
{
	int y;
	int r;
	int j;
	int k;
	int i;

	j = -1;
	i = 0;
	while (a[i] != -30)
		i++;
	while (++j != num)
	{
		k = j - 1;
		y = -1;
		r = -1;
		while (++k != (max * 2))
		{
			while (++r <= k)
				p[j][r] = -1;
			if (++y < i)
				p[j][k] = a[y];
			else
				p[j][k] = -1;
		}
	}
}
