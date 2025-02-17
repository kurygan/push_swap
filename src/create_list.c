/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:54:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/17 23:51:46 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *nb, bool *error)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	*error = false;
	if (nb[i] == '+' || nb[i] == '-')
	{
		if (!nb[i + 1])
			*error = true;
		if (nb[i++] == '-')
			sign *= -1;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		result = (result * 10) + (nb[i++] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (result * -1) < INT_MIN))
			return (*error = true, 0);
	}
	if (nb[i])
		*error = true;
	return (sign * result);
}

void	freestr(char **str)
{
	char	**temp;

	if (!str)
		return ;
	temp = str;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(str);
	str = NULL;
}

bool	if_duplicate(t_list **list)
{
	t_list	*current;
	t_list	*verif;

	current = *list;
	while (current && current->next != *list)
	{
		verif = current->next;
		while (verif && verif != current)
		{
			if (verif->i == current->i)
				return (true);
			verif = verif->next;
		}
		current = current->next;
	}
	return (false);
}

bool	create_list(char **str, t_list **fin_list)
{
	int		temp;
	bool	error;

	temp = 0;
	error = false;
	while (*str)
	{
		temp = ft_atoi(*str, &error);
		if (error == true)
			return (true);
		lstadd(fin_list, temp);
		str++;
	}
	if (!fin_list || !*fin_list || error)
		return (true);
	if ((*fin_list)->next)
		if (if_duplicate(fin_list))
			return (true);
	return (false);
}
