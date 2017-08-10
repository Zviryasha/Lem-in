/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 13:08:52 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/08 17:12:42 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		where_start(char *line)
{
	int u;

	u = -2;
	while (u == -2)
	{
		if (ft_strstr(line, "##start") && ft_strlen(line) == 7)
			return (1);
		if (line[0] == '#')
			return (0);
		else
			return (-1);
	}
	return (0);
}
