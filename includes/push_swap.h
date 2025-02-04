/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:23 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/03 14:49:50 by mkettab          ###   ########.fr       */
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

char	**ft_split(char const *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, char *src, int len);
bool	create_list(char **str, t_list **i);
bool	lstadd(t_list **list, int temp);
bool	if_duplicate(t_list **list);
void	lstclear(t_list **list);
void	freestr(char **str);
void	is_error(bool error);
void	ft_putstr_fd(char *str, int fd);
t_list	*lstgetlast(t_list **list);

#endif