/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_sort_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:00:55 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/14 14:59:50 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_sort_a(t_list **a, t_list **b, int *total)
{
	int		i;
	int		len;

	i = 0;
	len = lstsize(b);
	while (i < len)
	{
		get_biggest_target(a, b);
		get_median (a, b);
		get_cost(b, a);
		loop_sort_a(a, b, total);
		i++;
		do_op(pa, a, b, total);
	}
	while (lstgetindex(get_smallest(a), a))
	{
		if (get_biggest(a)->lower)
			do_op(rra, a, b, total);
		else
			do_op(ra, a, b, total);
	}
}

void	loop_sort_a(t_list **a, t_list **b, int *total)
{
	t_list	*smallest_cost;
	t_list	*smallest_target;

	smallest_cost = get_smallest_cost(b);
	smallest_target = smallest_cost->target;
	if (smallest_cost->lower == true && smallest_target->lower == true)
		while (lstgetindex(smallest_cost, b) && lstgetindex(smallest_target, a))
			do_op(rrr, a, b, total);
	if (smallest_cost->lower == false && smallest_target->lower == false)
		while (lstgetindex(smallest_cost, b) && lstgetindex(smallest_target, a))
			do_op(rr, a, b, total);
	while (lstgetindex(smallest_cost, b))
	{
		if (smallest_cost->lower)
			do_op(rrb, a, b, total);
		else
			do_op(rb, a, b, total);
	}
	while (lstgetindex(smallest_target, a))
	{
		if (smallest_target->lower)
			do_op(rra, a, b, total);
		else
			do_op(ra, a, b, total);
	}
}

void	get_biggest_target(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*node;

	temp_b = *b;
	while (1)
	{
		node = NULL;
		temp_a = *a;
		while (1)
		{
			if (temp_a->i > temp_b->i && (!node || temp_a->i < node->i))
				node = temp_a;
			if (temp_a->next == *a)
				break ;
			temp_a = temp_a->next;
		}
		if (!node)
			node = get_smallest(a);
		temp_b->target = node;
		if (temp_b->next == *b)
			break ;
		temp_b = temp_b->next;
	}
}

t_list	*get_smallest(t_list **list)
{
	t_list	*current;
	t_list	*smallest;

	current = *list;
	smallest = current;
	while (1)
	{
		if (current->i < smallest->i)
			smallest = current;
		if (current->next == *list)
			break ;
		current = current->next;
	}
	return (smallest);
}
