/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 02:33:46 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/06 04:37:27 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_list(t_list *list, int *total)
{
	int	temp;

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
	swap_list(a, &dummy);
	swap_list(b, &dummy);
	(*total)++;
}

void	rotate_list(t_list **list, bool reverse, int *total)
{
	if (!(*list) || !(*list)->next || !(*list)->prev)
		return ;
	if (reverse)
		*list = (*list)->prev;
	else
		*list = (*list)->next;
	(*total)++;
}

void	rotate_both(t_list **a, t_list **b, bool reverse, int *total)
{
	int dummy;
	
	dummy = 0;
	rotate_list(a, reverse, &dummy);
	rotate_list(b, reverse, &dummy);
	(*total)++;
}
