/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in-main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:38:49 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/09 01:31:45 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "stdio.h"

int		lem(char *line, char *rooms, char **to_st_ed, int **conect)
{
	int		u;
	int		y;
	int		i;
	char	*s;

	u = -2;
	s = "";
	while (get_next_line(0, &line))
	{
		if (u < 0)
			u = number(line, to_st_ed, &i, &s);
		if (u > 0 && ft_strcmp(line, ft_itoa(u)) != 0)
		{
			y = gg(&s, line);
			if (y == 6)
				i = lol(to_st_ed, rooms, &conect, line);
			i = starty(line, &to_st_ed, y, i);
			if ((y == 5 || y == 2 || y == 1) && i != -1)
				i = roomy(conect, line, &rooms, i);
		}
		if (i == -1 || y == -1)
			return (-1);
	}
	i = last(conect, rooms, to_st_ed, s);
	return (i);
}

char	*koko(char *line, char *s)
{
	char *f;
	char *r;

	f = ft_strjoin(s, line);
	r = ft_strjoin(f, "\n");
	return (r);
}

int		gg(char **s, char *line)
{
	int y;

	*s = koko(line, *s);
	y = wtf(line);
	if (y == 1 || y == 2)
	{
		get_next_line(0, &line);
		*s = koko(line, *s);
	}
	return (y);
}
