/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:39:07 by anespoul          #+#    #+#             */
/*   Updated: 2015/11/30 16:41:17 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		cc;
	size_t				i;

	str = s;
	cc = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cc)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
