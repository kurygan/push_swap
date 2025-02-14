/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_sort_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:17:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/14 20:20:37 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_sort_b(t_list **a, t_list **b, int *total)
{
	while (lstsize(a) > 3)
	{
		get_smallest_target(a, b);
		get_median(a, b);
		get_cost(a, b);
		loop_sort_b(a, b, total);
		do_op(pb, a, b, total);
	}
}

void	loop_sort_b(t_list **a, t_list **b, int *total)
{
	t_list	*smallest_cost;
	t_list	*smallest_target;

	smallest_cost = get_smallest_cost(a);
	smallest_target = smallest_cost->target;
	if (smallest_cost->lower == true && smallest_target->lower == true)
		while (lstgetindex(smallest_cost, a) && lstgetindex(smallest_target, b))
			do_op(rrr, a, b, total);
	if (smallest_cost->lower == false && smallest_target->lower == false)
		while (lstgetindex(smallest_cost, a) && lstgetindex(smallest_target, b))
			do_op(rr, a, b, total);
	while (lstgetindex(smallest_cost, a))
	{
		if (smallest_cost->lower == true)
			do_op(rra, a, b, total);
		else
			do_op(ra, a, b, total);
	}
	while (lstgetindex(smallest_target, b))
	{
		if (smallest_target->lower)
			do_op(rrb, a, b, total);
		else
			do_op(rb, a, b, total);
	}
}

void	get_smallest_target(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*node;

	temp_a = *a;
	while (1)
	{
		node = NULL;
		temp_b = *b;
		while (1)
		{
			if (temp_b->i < temp_a->i && (!node || temp_b->i > node->i))
				node = temp_b;
			if (temp_b->next == *b)
				break ;
			temp_b = temp_b->next;
		}
		if (!node)
			node = get_biggest(b);
		temp_a->target = node;
		if (temp_a->next == *a)
			break ;
		temp_a = temp_a->next;
	}
}

t_list	*get_biggest(t_list **list)
{
	t_list	*biggest;
	t_list	*current;

	current = *list;
	biggest = current;
	while (current)
	{
		if (current->i > biggest->i)
			biggest = current;
		if (current->next == *list)
			break ;
		current = current->next;
	}
	return (biggest);
}
