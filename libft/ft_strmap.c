/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:43:44 by anespoul          #+#    #+#             */
/*   Updated: 2015/12/23 12:10:05 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		str[i] = (*f)(*s++);
		i++;
	}
	str[i] = '\0';
	return (str);
}
