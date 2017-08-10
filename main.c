/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:17:38 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/09 05:30:22 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	char	*line;
	char	*rooms;
	char	**to_st_ed;
	int		k;
	int		**conect;

	rooms = NULL;
	to_st_ed = (char **)malloc(sizeof(char *) * 3);
	to_st_ed[1] = NULL;
	to_st_ed[2] = NULL;
	line = NULL;
	conect = NULL;
	k = lem(line, rooms, to_st_ed, conect);
	if (k == -1)
		ft_putstr("ERROR\n");
	free(line);
	return (0);
}

int		starty(char *line, char ***to_st_ed, int y, int i)
{
	if (i == -1 || y == -1)
		return (-1);
	if (y == 1)
	{
		if (to_st_ed[1] != NULL)
			return (-1);
		i = add_start(line, *to_st_ed);
	}
	if (y == 2)
		i = kik(line, *to_st_ed);
	return (i);
}

int		roomy(int **conect, char *line, char **rooms, int i)
{
	if (i == -1)
		return (-1);
	if (conect != NULL)
		return (-1);
	*rooms = add_room(line, *rooms);
	if (*rooms == NULL)
		return (-1);
	return (0);
}
