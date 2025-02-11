/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:45:48 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/10 15:16:33 by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*lstgetlast(t_list **list)
{
	t_list	*last;

	if (!(*list))
		return (NULL);
	last = *list;
	if (!last->next)
		return (*list);
	if (*list && (*list)->next)
		last = (*list)->next;
	while (last && last->next != *list)
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
	new->lower = false;
	new->prev = NULL;
	new->target = NULL;
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
	while (current && current->next != *list)
	{
		next = (current)->next;
		free(current);
		current = next;
	}
	free(current);
	*list = NULL;
}

int	lstsize(t_list **list)
{
	t_list	*current;
	int		len;

	current = *list;
	len = 0;
	while (current && current->next != *list)
	{
		len++;
		current = current->next;
	}
	len++;
	return (len);
}
