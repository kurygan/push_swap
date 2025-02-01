/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:45:48 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/01 03:12:20 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list *lstgetlast(t_list **list)
{
	t_list *last;

	last = *list;
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
		last = lstgetlast(list);
		last->next = new;
		new->prev = last;
		(*list)->prev = new;
	}
}

void	lstclear(t_list **list)
{
	t_list *next;

	while(*list)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
}