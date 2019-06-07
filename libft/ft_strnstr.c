/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:16:37 by anespoul          #+#    #+#             */
/*   Updated: 2015/11/30 12:43:50 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (i < n && s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while ((s1[i + j] == s2[j]) && ((i + j) < n))
			{
				if (s2[j + 1] == '\0')
					return ((char*)s1 + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
