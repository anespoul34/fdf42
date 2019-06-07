/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:58:15 by anespoul          #+#    #+#             */
/*   Updated: 2015/11/30 14:31:13 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	if (source <= dest)
	{
		source = src + (len - 1);
		dest = dst + (len - 1);
		while (len--)
		{
			*dest-- = *source--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
