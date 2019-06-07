/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:39:52 by anespoul          #+#    #+#             */
/*   Updated: 2015/12/01 12:02:02 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s1[i])
	{
		i++;
	}
	while (s2[n])
	{
		s1[i + n] = s2[n];
		n++;
	}
	s1[i + n] = '\0';
	return (s1);
}