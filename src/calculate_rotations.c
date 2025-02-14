/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:10:55 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/13 22:51:17 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_ra(t_list **a, t_list *top_a, t_rotate_calc *ops)
{
	int	list_size;

	list_size = lstsize(a);
	if (top_a->lower == true)
		ops->rra = list_size - lstgetindex(top_a, a);
	else
		ops->ra = lstgetindex(top_a, a);
}

void	calculate_rb(t_list **b, t_list *top_b, t_rotate_calc *ops)
{
	int	list_size;

	list_size = lstsize(b);
	if (top_b->lower == true)
		ops->rrb = list_size - lstgetindex(top_b, b);
	else
		ops->rb = lstgetindex(top_b, b);
}

void	calculate_rr(t_rotate_calc *ops)
{
	if (ops->ra && ops->rb)
	{
		if (ops->ra > ops->rb)
		{
			ops->rr = ops->rb;
			ops->ra -= ops->rb;
			ops->rb = 0;
		}
		else
		{
			ops->rr = ops->ra;
			ops->rb -= ops->ra;
			ops->ra = 0;
		}
	}
}

void	calculate_rrr(t_rotate_calc *ops)
{
	if (ops->rra && ops->rrb)
	{
		if (ops->rra > ops->rrb)
		{
			ops->rrr = ops->rrb;
			ops->rra -= ops->rrb;
			ops->rrb = 0;
		}
		else
		{
			ops->rrr = ops->rra;
			ops->rrb -= ops->rra;
			ops->rra = 0;
		}
	}
}