/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:06:37 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/04 02:30:46 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(char *str)
{
	long	nbr;
	int		index;
	int		sign;

	nbr = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
		if (!(*str))
			return (is_error(true), 0);
	}
	while (*str >= '0' && *str <= '9')
	{
		index = (*str) - '0';
		nbr = (nbr * 10) + index;
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (is_error(true), 0);
		str++;
	}
	if (*str)
		return (is_error(true), 0);
	return (nbr * sign);
}

void	freestr(char **str)
{
	char	**temp;

	temp = str;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(str);
	str = NULL;
}

bool	if_duplicate(t_list **list)
{
	t_list	*current;
	t_list	*verif;

	current = *list;
	while (current && current->next != *list)
	{
		verif = current->next;
		while (verif && verif != current)
		{
			if (verif->i == current->i)
				return (true);
			verif = verif->next;
		}
		current = current->next;
	}
	return (false);
}

bool	create_list(char **str, t_list **fin_list)
{
	int	temp;

	temp = 0;
	while (*str)
	{
		temp = ft_atoi(*str);
		lstadd(fin_list, temp);
		str++;
	}
	if (!fin_list || !*fin_list)
		return (true);
	if (if_duplicate(fin_list))
		return (true);
	return (false);
}
