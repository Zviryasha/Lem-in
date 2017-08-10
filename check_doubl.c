/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:23:53 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/07 17:10:57 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_dubl(char *rm, char **st_ed)
{
	char	**s;
	int		i;

	if (ft_strcmp(st_ed[1], st_ed[2]) == 0)
		return (-1);
	s = ft_strsplit(rm, ' ');
	i = nano(s);
	if (i == -1)
		return (-1);
	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (1);
}

int		nano(char **s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[j] != NULL)
		{
			if (i != j)
			{
				if (ft_strcmp(s[i], s[j]) == 0)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
