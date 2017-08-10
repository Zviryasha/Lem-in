/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 16:55:23 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/09 03:03:14 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_number(char *line)
{
	int i;

	i = 0;
	if (ft_strstr(line, "##start") && ft_strlen(line) == 7)
	{
		free(line);
		return (-1);
	}
	if (ft_strstr(line, "##end") && ft_strlen(line) == 5)
	{
		free(line);
		return (-1);
	}
	if (line[0] == '#')
	{
		free(line);
		return (-2);
	}
	if (my_atoi(line) <= 0)
	{
		free(line);
		return (-1);
	}
	return (uou(line));
}

int		uou(char *line)
{
	if (my_atoi(line) > 0 && my_atoi(line) <= 2147483647)
	{
		if (test_str(line) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		return (ft_atoi(line));
	}
	return (-1);
}

int		test_str(char *s)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 48 && s[i] <= 57)
			c++;
		else
			return (-1);
		i++;
	}
	return (1);
}

int		count_ants(char *line)
{
	int u;

	u = -2;
	while (u == -2)
	{
		u = is_number(line);
		if (u == -2)
			get_next_line(0, &line);
	}
	if (u == -1)
		return (-1);
	return (u);
}
