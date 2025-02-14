/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:39:15 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/14 14:57:56 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_op(t_op operations, t_list **a, t_list **b, int *total)
{
	if (operations == pa)
		return (push(b, a, total), ft_putstr_fd("pa\n", 1));
	else if (operations == pb)
		return (push(a, b, total), ft_putstr_fd("pb\n", 1));
	else if (operations == sa)
		return (swap_list(*a, total), ft_putstr_fd("sa\n", 1));
	else if (operations == sb)
		return (swap_list(*b, total), ft_putstr_fd("sb\n", 1));
	else if (operations == ss)
		return (swap_both(*a, *b, total), ft_putstr_fd("ss\n", 1));
	else if (operations == ra)
		return (rotate_list(a, false, total), ft_putstr_fd("ra\n", 1));
	else if (operations == rb)
		return (rotate_list(b, false, total), ft_putstr_fd("rb\n", 1));
	else if (operations == rr)
		return (rotate_both(a, b, false, total), ft_putstr_fd("rr\n", 1));
	else if (operations == rra)
		return (rotate_list(a, true, total), ft_putstr_fd("rra\n", 1));
	else if (operations == rrb)
		return (rotate_list(b, true, total), ft_putstr_fd("rrb\n", 1));
	else if (operations == rrr)
		return (rotate_both(a, b, true, total), ft_putstr_fd("rrr\n", 1));
}

void	sort(t_list **a, t_list **b, int *total)
{
	if (lstsize(a) <= 3)
	{
		sort_short(a, b, total);
		return ;
	}
	do_op(pb, a, b, total);
	do_op(pb, a, b, total);
	rev_sort_b(a, b, total);
	sort_short(a, b, total);
	rev_sort_a(a, b, total);
}

void	sort_short(t_list **a, t_list **b, int *total)
{
	if (lstsize(a) == 2)
		if ((*a)->i > (*a)->next->i)
			do_op(sa, a, b, total);
	if (lstsize(a) == 3)
	{
		if (get_biggest(a) == (*a)->next)
			do_op(rra, a, b, total);
		else if (get_biggest(a) == *a)
			do_op(ra, a, b, total);
		if ((*a)->i > (*a)->next->i)
			do_op(sa, a, b, total);
	}
}
