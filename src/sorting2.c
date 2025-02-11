/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:34:28 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/02/11 05:36:22 by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_cost(t_list **costed)
{
	t_list	*temp_costed;
	t_list	*temp_target;
	int		cost;
	
	temp_costed = *costed;
	temp_target = temp_costed->target;
	
	while ((temp_costed->prev != lstgetlast(&temp_costed)) || (temp_target->prev != lstgetlast(temp_costed)))
	{
		if
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
