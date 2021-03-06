/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:42:36 by opanchen          #+#    #+#             */
/*   Updated: 2016/12/08 20:01:31 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getlet(char const *s, char c)
{
	size_t	j;

	j = 0;
	while ((*s != '\0') && ((char)*s != c))
	{
		s++;
		j++;
	}
	return (j);
}
