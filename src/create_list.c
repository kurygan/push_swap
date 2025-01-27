/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:06:37 by mkettab           #+#    #+#             */
/*   Updated: 2025/01/27 22:16:43 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(char *str)
{
	int nbr;
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
	return (nbr * sign);
}

t_list *lstgetlast(t_list *list)
{
	t_list *last;

	last = list;
	while(last && last->next)
		last = last->next;
	return (last);
}

void	lstadd(t_list **list, int temp)
{
	t_list *last;
	t_list *new;

	new = malloc(sizeof(t_list));
	if(!new)
		return ;
	new->i = temp;
	new->next = NULL;
	new->prev = NULL;
	if (!(*list))
		*list = new;
	else
	{
		last = lstgetlast(*list);
		last->next = new;
		new->prev = last;
		(*list)->prev = new;
	}
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

