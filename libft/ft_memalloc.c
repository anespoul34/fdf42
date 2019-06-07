/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:12:25 by anespoul          #+#    #+#             */
/*   Updated: 2015/12/05 11:19:33 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;
	int				i;

	i = 0;
	s = malloc(size * sizeof(void));
	if (!s)
		return (NULL);
	while (size--)
	{
		s[i] = '\0';
		i++;
	}
	s[i] = '\0';
	return (s);
}
