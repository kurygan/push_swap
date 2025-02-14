/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 04:16:24 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/14 21:47:24 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*strduped;
	int		i;

	strduped = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!strduped)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strduped[i] = s1[i];
		i++;
	}
	strduped[i] = 0;
	return (strduped);
}

char	*ft_strncpy(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
