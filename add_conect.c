/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_conect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:12:51 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/08 12:39:43 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_conect(char *line, int **con, char *rooms)
{
	int		i;
	char	**s;
	int		k;
	char	**zv;

	s = ft_strsplit(rooms, ' ');
	k = is_con(line);
	if (k == -1)
		return (-1);
	zv = ft_strsplit(line, '-');
	i = sk(s, zv, con);
	if (i == -1)
		return (-1);
	i = -1;
	while (s[++i] != NULL)
		free(s[i]);
	free(s);
	free(zv[0]);
	free(zv[1]);
	free(zv);
	return (1);
}

int		**setin(char **zv, char **s, int **con)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_strcmp(zv[0], s[i]) != 0)
		i++;
	while (ft_strcmp(zv[1], s[j]) != 0)
		j++;
	con[i][j] = 1;
	con[j][i] = 1;
	return (con);
}

int		is_con(char *line)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
		{
			if (line[i + 1] == '\0')
				return (-1);
			c++;
		}
		if (line[i] == ' ' || line[i] == '\t')
			return (-1);
		i++;
	}
	if (line[0] == '-')
		return (-1);
	if (c != 1)
		return (-1);
	return (1);
}

int		**set_conect(char *rooms, int **con)
{
	int		i;
	char	**s;
	int		j;
	int		k;

	i = 0;
	s = ft_strsplit(rooms, ' ');
	while (s[i] != NULL)
		i++;
	con = (int **)malloc(sizeof(int *) * i);
	con[i] = NULL;
	j = -1;
	while (++j < i)
	{
		k = -1;
		con[j] = (int *)malloc(sizeof(int) * i);
		while (++k < i)
			con[j][k] = 0;
	}
	i = -1;
	while (s[++i] != NULL)
		free(s[i]);
	free(s);
	return (con);
}
