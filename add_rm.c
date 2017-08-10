/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 13:20:58 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/08 18:02:00 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*add_room(char *line, char *rooms)
{
	int i;
	int k;

	k = 0;
	i = check_rm(line);
	if (i != -1)
	{
		if (rooms == NULL)
			rooms = riri(rooms, &i, line);
		else
			rooms = roro(&i, line, rooms);
	}
	else
	{
		if (rooms != NULL)
			free(rooms);
		rooms = NULL;
	}
	return (rooms);
}

char	*riri(char *rooms, int *i, char *line)
{
	int k;

	k = 0;
	rooms = ft_strnew(*i + 1);
	while (*i > 0)
	{
		rooms[k] = line[k];
		k++;
		(*i)--;
	}
	rooms[k] = '\0';
	return (rooms);
}

char	*roro(int *i, char *line, char *rooms)
{
	int		k;
	char	*r;
	char	*s;

	k = 1;
	s = ft_strnew(*i + 2);
	s[0] = ' ';
	while (*i > 0)
	{
		s[k] = line[k - 1];
		k++;
		(*i)--;
	}
	s[k] = '\0';
	r = rooms;
	rooms = ft_strjoin(rooms, s);
	free(s);
	if (r != NULL)
		free(r);
	return (rooms);
}
