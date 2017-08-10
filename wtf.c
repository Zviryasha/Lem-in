/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 12:14:26 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/09 00:32:44 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		wtf(char *line)
{
	int i;
	int c;
	int k;

	k = 0;
	i = wot(line);
	if (i != 0)
		return (i);
	i = 0;
	c = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			c++;
		if (line[i] == '-')
			k++;
		i++;
	}
	if (c == 2 || c == 1)
		return (5);
	if (k == 1)
		return (6);
	if (c > 2)
		return (-1);
	return (-1);
}

int		wot(char *line)
{
	if (ft_strstr(line, "##start") && ft_strlen(line) == 7)
	{
		free(line);
		return (1);
	}
	if (ft_strstr(line, "##end") && ft_strlen(line) == 5)
	{
		free(line);
		return (2);
	}
	if (line[0] == '#')
	{
		free(line);
		return (3);
	}
	return (0);
}
