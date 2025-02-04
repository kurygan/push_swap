/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 02:33:46 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/04 22:28:28by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_list(t_list *list, int *total)
{
	int temp;

	if (!list || !list->next)
		return ;
	temp = list->i;
	list->i = list->next->i;
	list->next->i = temp;
	(*total)++;
}

void	swap_both(t_list *a, t_list *b, int *total)
{
	int dummy;

	dummy = 0;
	if (!a || !a->next || !b || !b->next)
		return ;
	swap_list(a, &dummy);
	swap_list(b, &dummy);
	(*total)++;
}

void	rotate_list(t_list **list, int *total, bool reverse)
{
	if(!(*list) || !(*list)->next || !(*list)->prev)
		return ;
	if(reverse)
		*list = (*list)->prev;
	else
		*list = (*list)->next;
	(*total)++;
}

void	rotate_both(t_list **a, t_list **b, int *total, bool reverse)
{
	int dummy;

	dummy = 0;
	if (!(*a) || !(*a)->next || !(*a)->prev
		|| !(*b) || !(*b)->next || !(*b)->prev)
		return ;
	rotate_list(a, &dummy, reverse);
	rotate_list(b, &dummy, reverse);
	(*total)++;
}

void	push(t_list **sender, t_list **receiver, int *total)
{
	t_list *sent;

	if (!(*sender))
		return ;
	sent = *sender;
	*sender = (*sender)->next;
	if (*sender)
		(*sender)->prev = NULL;
	if (!(*receiver))
	{
		*receiver = sent;
		(*receiver)->next = NULL;
		(*receiver)->prev = NULL;
	}
	else
	{
		sent->next = *receiver;
		(*receiver)->prev = sent;
		*receiver = sent;
	}
	(*total)++;
}
