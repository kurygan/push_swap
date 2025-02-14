/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:34:28 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/02/13 23:33:03 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_cost(t_list **costed, t_list **target)
{
	t_list	*temp_costed;
	t_list	*temp_target;

	temp_costed = *costed;
	temp_target = temp_costed->target;
	while (1)
	{
		temp_costed->cost = calculate_op(costed, target,
				temp_costed, temp_target);
		if (temp_costed->next == *costed)
			break ;
		temp_costed = temp_costed->next;
		temp_target = temp_costed->target;
	}
}

void	get_median(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		len_a;
	int		len_b;

	len_a = lstsize(a);
	len_b = lstsize(b);
	temp_a = *a;
	temp_b = *b;
	if (lstsize(a) > 2)
		set_median(temp_a, len_a);
	if (lstsize(b) > 2)
		set_median(temp_b, len_b);
}

void	set_median(t_list *temp, int len)
{
	int	index;

	index = 0;
	while (index < len / 2)
	{
		temp->lower = false;
		index++;
		temp = temp->next;
	}
	while (index < len)
	{
		temp->lower = true;
		index++;
		temp = temp->next;
	}
}

int	calculate_op(t_list **a, t_list **b, t_list *top_a, t_list *top_b)
{
	t_rotate_calc	ops;

	(void)0, ops.ra = 0, ops.rb = 0, ops.rr = 0;
	(void)0, ops.rra = 0, ops.rrb = 0, ops.rrr = 0;
	calculate_ra(a, top_a, &ops);
	calculate_rb(b, top_b, &ops);
	calculate_rr(&ops);
	calculate_rrr(&ops);
	return (ops.ra + ops.rb + ops.rr + ops.rra + ops.rrb + ops.rrr);
}

t_list	*get_smallest_cost(t_list **a)
{
	t_list	*temp_a;
	t_list	*lowest;

	temp_a = *a;
	lowest = NULL;
	while(1)
	{
		if (!lowest || (lowest->cost > temp_a->cost))
			lowest = temp_a;
		if (temp_a->next == *a)
			break ;
		temp_a = temp_a->next;
	}
	return (lowest);
}
