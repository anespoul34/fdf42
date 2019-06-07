/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:13:04 by anespoul          #+#    #+#             */
/*   Updated: 2015/12/23 12:10:50 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strtroll(char const *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		i++;
		n++;
	}
	return (n);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char*)malloc((ft_strtroll(s) + 1) * sizeof(*s));
	if (!str)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
	}
	while (s[i + j])
	{
		str[j] = s[i + j];
		j++;
	}
	while (s[i + j - 1] == ' ' || s[i + j - 1] == '\n' || s[i + j - 1] == '\t')
	{
		str[j] = '\0';
		j--;
	}
	str[j] = '\0';
	return (str);
}
