/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:40:55 by anespoul          #+#    #+#             */
/*   Updated: 2016/03/15 15:41:03 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_strlensplit(char const *s, char c)
{
	int		i;
	int		len;
	int		start;

	i = 0;
	len = 0;
	start = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i - 1] == c && s[i] != '\0')
			len++;
		if (s[0] != c && start == 0)
		{
			len++;
			start++;
		}
		i++;
	}
	return (len);
}

static int		ft_strfindlen(char const *s, char c, int start)
{
	int	count;

	count = 0;
	while (s[start + count] != 0 && s[start + count] != c)
		count++;
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len1d;
	int		len2d;
	char	**ret;

	i = 0;
	j = 0;
	len1d = ft_strlensplit(s, c);
	ret = (char **)malloc(sizeof(char*) * (len1d + 1));
	if (ret == NULL)
		return (NULL);
	while (s[i] != 0 && len1d)
	{
		if (s[i] != c)
		{
			len2d = ft_strfindlen(s, c, i);
			ret[j++] = ft_strsub(s, i, len2d);
			i += len2d;
			len1d--;
		}
		i++;
	}
	ret[j] = 0;
	return (ret);
}
