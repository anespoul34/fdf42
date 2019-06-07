/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:20:57 by anespoul          #+#    #+#             */
/*   Updated: 2015/11/30 16:21:58 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s2[i] != '\0' && i < n)
	{
		if ((unsigned char)s2[i] != (unsigned char)s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((i == n) && ((unsigned char)s2[i - 1] == (unsigned char)s1[i - 1]))
		return (0);
	if ((unsigned char)s1[i] != '\0')
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
