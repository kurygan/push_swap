/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 02:33:46 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/06 03:49:28 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_list(t_list *list)
{
	int	temp;

	if (!list || !list->next)
		return ;
	temp = list->i;
	list->i = list->next->i;
	list->next->i = temp;
}

void	rotate_list(t_list **list, bool reverse)
{
	if (!(*list) || !(*list)->next || !(*list)->prev)
		return ;
	if (reverse)
		*list = (*list)->prev;
	else
		*list = (*list)->next;
}
