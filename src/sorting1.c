/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:39:15 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/13 19:44:02 by mkettab          ###   ########.fr       */
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
		return (rotate_list(a, true, total), ft_putstr_fd("ra\n", 1));
	else if (operations == rrb)
		return (rotate_list(b, true, total), ft_putstr_fd("rb\n", 1));
	else if (operations == rrr)
		return (rotate_both(a, b, true, total), ft_putstr_fd("rr\n", 1));
}

void	sort(t_list **a, t_list **b, int *total)
{
	do_op(pb, a, b, total);
	do_op(pb, a, b, total);
	rev_sort_b(a, b, total);
}

void	rev_sort_b(t_list **a, t_list **b, int *total)
{
	t_list	*temp_b;
	t_list	*temp_a;

	temp_b = *b;
	temp_a = *a;
	get_smallest_target(a, b);
	get_median(a, b);
	get_cost(&temp_a, &temp_b);
	(*total)++;
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
		if (temp_b->i < temp_a->i)
			node = temp_b;
		while (1)
		{
			if (temp_b->i < temp_a->i && (!node || temp_b->i > node->i))
				node = temp_b;
			if(temp_b->next == *b)
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