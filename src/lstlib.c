/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:45:48 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/03 23:27:19 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*lstgetlast(t_list **list)
{
	t_list	*last;

	last = *list;
	if(!last->next)
		return (*list);
	last = (*list)->next;
	while(last->next != *list)
		last = last->next;
	return (last);
}

bool	lstadd(t_list **list, int temp)
{
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (true);
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
		new->next = *list;
		(*list)->prev = new;
	}
	return (false);
}

void	lstclear(t_list **list)
{
	t_list	*next;
	t_list	*current;

	current = *list;
	while (current->next != *list)
	{
		next = (current)->next;
		free(current);
		current = next;
	}
	free(current);
	*list = NULL;
}
