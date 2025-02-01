/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:26:01 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/01 03:54:41 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;
	
	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*non_const_s;
	char			*subbed;

	if (!s)
		return (NULL);
	i = 0;
	non_const_s = (char *)s;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	subbed = malloc(sizeof(char) * len + 1);
	if (!subbed)
		return (NULL);
	while (i < start && non_const_s[i])
		i++;
	ft_strncpy(subbed, &non_const_s[i], len);
	return (subbed);
}

static int	ft_count_words(char const *s)
{
	int	counts;
	int	i;

	i = 0;
	counts = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i])
			counts++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (counts);
}

static char	**ft_free_all(char **splitted, int j)
{
	while (j-- > 0)
		free(splitted[j]);
	free(splitted);
	return (NULL);
}

char	**ft_split(char const *s)
{
	char	**splitted = NULL;
	int		i;
	int		start;
	int		j;

	if (!s)
		return (NULL);
	splitted = malloc(sizeof(char *) * (ft_count_words(s) + 1));
	if (!splitted)
		return (NULL);
	(void)0, i = 0, j = 0, start = 0;
	while (j < ft_count_words(s))
	{
		while (s[i] && s[i] == ' ')
			i++;
		start = i;
		while (s[i] && s[i] != ' ')
			i++;
		splitted[j] = ft_substr(s, start, i - start);
		if (!splitted[j])
			return (ft_free_all(splitted, j));
		j++;
	}
	return (splitted[j] = NULL, splitted);
}
