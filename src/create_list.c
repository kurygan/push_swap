/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:06:37 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/01 00:48:49 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(char *str)
{
	long nbr;
	int index;
	int sign;
	
	nbr = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if(*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		index = (*str) - '0';
		nbr = (nbr * 10) + index;
		str++;
	}
	if (*str)
		exit(1);
	if (nbr > INT_MAX || nbr < INT_MIN)
		exit(1);
	return (nbr * sign);
}

void	freestr(char **str)
{
	while(*str)
	{
		free(*str);
		str++;
	}
	free(str);
	str = NULL;
}

bool if_duplicate(t_list **list)
{
	t_list *current;
	t_list *verif;
	
	current = *list;
	while (current)
	{
		verif = current->next;
		while (verif)
		{
			if (verif->i == current->i)
				return (true);
			verif = verif->next;
		}
		current = current->next;
	}
	return (false);
}

void	create_list(char **str, t_list **fin_list)
{
	int temp;

	temp = 0;
	while(*str)
	{
		temp = ft_atoi(*str);
		lstadd(fin_list, temp);
		str++;
	}
	if (if_duplicate(fin_list) == true)
		exit(1);
}
