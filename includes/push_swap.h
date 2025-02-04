/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:23 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/04 05:54:09 by mkettab          ###   ########.fr       */
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
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;


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
t_list	*lstgetlast(t_list **list);

// operations
void	swap_list(t_list *list, int *total);
void	rotate_list(t_list **list, int *total, bool reverse);
void	push(t_list **sender, t_list**reciever, int *total);
void	swap_both(t_list *a, t_list *b, int *total);
void	rotate_both(t_list **a, t_list **b, int *total, bool reverse);

// miscellaneous
void	is_error(bool error);
void	ft_putstr_fd(char *str, int fd);
bool	if_duplicate(t_list **list);

#endif