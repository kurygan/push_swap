/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:34:28 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/02/12 03:26:19 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_cost(t_list **costed, t_list **target)
{
	t_list	*temp_costed;
	t_list	*temp_target;
	int		cost;
	int		index_a;
	int		index_b;

	temp_costed = *costed;
	temp_target = temp_costed->target;
	index_a = lstgetindex(temp_costed, costed);
	index_b = lstgetindex(temp_target, target);
	while (1)
	{
		while (index_a)
		{
			if (temp_costed->lower == false && temp_target->lower == false)
				{
					do_op(rr, costed, target, &cost);
					cost++;
				}
    else if (temp_costed->lower == true && temp_target->lower == true)
    {
        do_op(rrr, costed, target, &cost);
        cost++;
    }
    else
    {
        if (temp_costed->lower == false)
            do_op(ra, costed, target, &cost);
        else
            do_op(rra, costed, target, &cost);
        if (temp_target->lower == false)
            do_op(rb, costed, target, &cost);
        else
            do_op(rrb, costed, target, &cost);
        cost += 2;
    }
    index_a--;
    index_b--;
		}
		if (temp_costed->next == *costed)
			break ;
		temp_costed = temp_costed->next;
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
	set_median(temp_a, len_a);
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
