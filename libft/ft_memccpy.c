/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:47:56 by anespoul          #+#    #+#             */
/*   Updated: 2015/11/28 15:39:43 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dest;
	const char	*source;
	size_t		i;

	dest = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		if (source[i] == c)
		{
			dest[i] = source[i];
			return (dst + i + 1);
		}
		dest[i] = source[i];
		i++;
	}
	return (NULL);
}
