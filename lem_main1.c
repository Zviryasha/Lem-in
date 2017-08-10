/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_main1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:07:34 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/09 07:33:21 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		number(char *line, char **to_st_ed, int *i, char **s)
{
	int		u;
	char	*f;

	*s = koko(line, *s);
	u = is_number(line);
	f = ft_itoa(u);
	to_st_ed[0] = (char *)malloc(sizeof(char) * (ft_strlen(f) + 1));
	to_st_ed[0] = ft_strcpy(to_st_ed[0], f);
	if (u == -1)
		*i = -1;
	return (u);
}

int		lol(char **to_st_ed, char *rooms, int ***conect, char *line)
{
	int i;

	if (to_st_ed[1] == NULL || to_st_ed[2] == NULL)
		return (-1);
	i = check_dubl(rooms, to_st_ed);
	if (i == -1)
		return (-1);
	if (*conect == NULL)
		*conect = set_conect(rooms, *conect);
	i = add_conect(line, *conect, rooms);
	free(line);
	return (i);
}

int		kik(char *line, char **to_st_ed)
{
	int i;

	if (6 == wtf(line))
		return (-1);
	if (to_st_ed[2] != NULL)
		return (-1);
	i = add_end(line, to_st_ed);
	return (i);
}

int		last(int **conect, char *rooms, char **to_st_ed, char *s)
{
	int		*a;

	if (conect == NULL)
		return (-1);
	a = solve(rooms, conect, to_st_ed);
	if (a[0] == -1)
		return (-1);
	ft_putstr_c(s);
	ft_putchar('\n');
	pr(a, rooms, to_st_ed[0]);
	return (0);
}
