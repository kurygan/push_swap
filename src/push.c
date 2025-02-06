/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:48:42 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/06 04:37:57 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushed(t_list **receive, t_list *sent)
{
	t_list	*last_receive;

	if (!(*receive))
	{
		sent->prev = NULL;
		sent->next = NULL;
		*receive = sent;
	}
	else
	{
		last_receive = lstgetlast(receive);
		sent->next = *receive;
		(*receive)->prev = sent;
		sent->prev = last_receive;
		last_receive->next = sent;
		*receive = sent;
	}
}

void	push(t_list **sender, t_list **receive, int *total)
	{
	t_list	*sent;
	t_list	*last_send;

	if (!(*sender))
		return ;
	sent = *sender;
	last_send = (*sender)->prev;
	*sender = (*sender)->next;
	if (*sender)
	{
		(*sender)->prev = last_send;
		last_send->next = *sender;
	}
	pushed(receive, sent);
	(*total)++;
}
