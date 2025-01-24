/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:06:37 by mkettab           #+#    #+#             */
/*   Updated: 2025/01/15 22:23:19 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(char *str)
{
	int nbr;
	
	nbr = 1;
	if (*str++ == '-')
		nbr = -nbr;
	while (*str >= '0' && *str <= '9')
	{
		nbr *= (*str) - '0';
		nbr *= 10;
		str++;
	}
	return (nbr);
}

t_list *lstgetlast(t_list *list)
{
	t_list *last;

	last = list;
	while(last && last->next)
		last = last->next;
	return (last);
}

void	lstadd(t_list *list, int temp)
{
	t_list *last;
	t_list *new;

	last = lstgetlast(list);
	new = malloc(sizeof(t_list));
	if(!new)
		return ;
	new->next = NULL;
	new->i = temp;
	last->next = new;
}

void	create_list(char **str, t_list *fin_list)
{
	int temp;

	temp = 0;
	while(*str)
	{
		temp = ft_atoi(*str);
		lstadd(fin_list, temp);
	}
}
