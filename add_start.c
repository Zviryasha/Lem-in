/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:41:21 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/08 15:37:32 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_start(char *line, char **s)
{
	int i;

	if (line[0] == '#')
		return (-1);
	if (check_rm(line) == -1)
		return (-1);
	i = 0;
	while (line[i] != ' ')
		i++;
	s[1] = ft_strnew(i + 1);
	i = 0;
	while (line[i] != ' ')
	{
		s[1][i] = line[i];
		i++;
	}
	s[1][i] = '\0';
	if (s[1] == NULL)
		return (-1);
	return (1);
}

int		add_end(char *line, char **s)
{
	int i;

	if (line[0] == '#')
		return (-1);
	if (check_rm(line) == -1)
		return (-1);
	i = 0;
	while (line[i] != ' ')
		i++;
	s[2] = ft_strnew(i + 1);
	i = 0;
	while (line[i] != ' ')
	{
		s[2][i] = line[i];
		i++;
	}
	s[2][i] = '\0';
	if (s[2] == NULL)
		return (-1);
	return (1);
}
