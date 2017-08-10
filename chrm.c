/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 14:53:27 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/07 17:14:04 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_rm(char *line)
{
	int		i;
	int		c;
	char	*room;

	i = -1;
	c = 0;
	if (line[0] == 'L')
		return (-1);
	while (line[++i] != '\0')
	{
		if (line[i] == ' ' && line[i + 1] != '\0')
			c++;
	}
	if (c != 2)
		return (-1);
	room = NULL;
	room = kom(&i, room, line);
	i = yy(&i, line);
	if (i == -1)
		return (-1);
	i = ft_strlen(room);
	free(room);
	return (i);
}

int		yy(int *i, char *line)
{
	char *x;
	char *y;

	x = NULL;
	x = kim(i, line, x);
	y = NULL;
	y = kum(i, line, y);
	if (test_str(x) == -1 || test_str(y) == -1)
		return (-1);
	if ((my_atoi(x) < -2147483648 || my_atoi(x) > 2147483647)
			|| (my_atoi(y) < -2147483648 || my_atoi(y) > 2147483647))
		return (-1);
	if (x != NULL)
		free(x);
	if (y != NULL)
		free(y);
	return (0);
}

char	*kum(int *i, char *line, char *y)
{
	int j;

	j = 0;
	while (line[*i] != '\0')
	{
		(*i)++;
		j++;
	}
	y = ft_strnew(j + 1);
	*i = *i - j;
	j = 0;
	while (line[*i] != '\0')
	{
		y[j] = line[*i];
		(*i)++;
		j++;
	}
	y[j] = '\0';
	return (y);
}

char	*kim(int *i, char *line, char *x)
{
	int j;

	j = 0;
	while (line[*i] != ' ')
	{
		j++;
		(*i)++;
	}
	x = ft_strnew(j + 1);
	*i = *i - j - 1;
	j = 0;
	while (line[*i] != ' ')
	{
		x[j] = line[*i];
		(*i)++;
		j++;
	}
	x[j] = '\0';
	(*i)++;
	return (x);
}

char	*kom(int *i, char *room, char *line)
{
	int j;

	room = ft_strnew(ft_strlen(line) + 100);
	*i = 0;
	j = 0;
	while (line[j] != ' ')
	{
		room[j] = line[j];
		j++;
		(*i)++;
	}
	room[j] = '\0';
	*i = *i + 2;
	return (room);
}
