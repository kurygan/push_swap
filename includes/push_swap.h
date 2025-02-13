/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:23 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/13 19:21:22 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				i;
	int				cost;
	bool			lower;
	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef enum s_op
{
	pa,
	pb,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_op;

typedef struct s_rotate_calc
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_rotate_calc;

// str tweaks
char	**ft_split(char const *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, char *src, int len);
void	freestr(char **str);

// list things
bool	create_list(char **str, t_list **i);
bool	lstadd(t_list **list, int temp);
void	lstclear(t_list **list);
int		lstsize(t_list **list);
t_list	*lstgetlast(t_list **list);
int		lstgetindex(t_list *target_node, t_list **list);

// operations
void	do_op(t_op operations, t_list **a, t_list **b, int *total);
void	swap_list(t_list *list, int *total);
void	rotate_list(t_list **list, bool reverse, int *total);
void	push(t_list **sender, t_list**reciever, int *total);
void	pushed(t_list **receive, t_list *sent);
void	swap_both(t_list *a, t_list *b, int *total);
void	rotate_both(t_list **a, t_list **b, bool reverse, int *total);

// sorting
void	sort(t_list **a, t_list **b, int *total);
void	rev_sort_b(t_list **a, t_list **b, int *total);
void	get_smallest_target(t_list **a, t_list **b);
t_list	*get_biggest(t_list **list);
void	get_cost(t_list **costed, t_list **target);
void	get_median(t_list **a, t_list **b);
void	set_median(t_list *temp, int len);

// calculate cost
int		calculate_op(t_list **a, t_list **b, t_list *top_a, t_list *top_b);
void	calculate_ra(t_list **a, t_list *top_a, t_rotate_calc *ops);
void	calculate_rb(t_list **b, t_list *top_b, t_rotate_calc *ops);
void	calculate_rr(t_rotate_calc *ops);
void	calculate_rrr(t_rotate_calc *ops);

// miscellaneous
void	is_error(bool error);
void	ft_putstr_fd(char *str, int fd);
bool	if_duplicate(t_list **list);

#endif