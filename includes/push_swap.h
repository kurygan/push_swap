/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:23 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/11 05:30:32 by tylerlover9      ###   ########.fr       */
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
void	get_cost(t_list **costed);
void	get_median(t_list **a, t_list **b);
void	set_median(t_list *temp, int len);

// miscellaneous
void	is_error(bool error);
void	ft_putstr_fd(char *str, int fd);
bool	if_duplicate(t_list **list);

#endif