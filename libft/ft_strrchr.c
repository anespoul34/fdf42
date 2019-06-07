/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:45:50 by anespoul          #+#    #+#             */
/*   Updated: 2015/11/30 14:43:23 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	if (str[i] == c)
		return ((char*)str + i);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			return ((char*)str + i);
		}
		i--;
	}
	return (NULL);
}
