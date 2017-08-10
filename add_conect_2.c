/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_conect_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:04:23 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/08 10:45:48 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		sk(char **s, char **zv, int **con)
{
	int j;
	int p;

	p = 0;
	j = 0;
	while (s[j] != NULL)
	{
		if (ft_strcmp(s[j], zv[1]) == 0)
			p++;
		if (ft_strcmp(s[j], zv[0]) == 0)
			p++;
		j++;
	}
	if (p != 2)
		return (-1);
	con = setin(zv, s, con);
	return (0);
}
