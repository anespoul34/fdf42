/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:00:51 by anespoul          #+#    #+#             */
/*   Updated: 2015/12/29 12:58:25 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_intlen(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		i = 2;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_intlen(n);
	i = len;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n > 9)
	{
		len = len - 1;
		str[len] = (n % 10) + 48;
		n = n / 10;
	}
	str[len - 1] = n + 48;
	str[i] = '\0';
	return (str);
}
