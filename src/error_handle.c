/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 03:34:04 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/14 15:17:19 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	is_error(bool error)
{
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}

void	free_all(int argc, char **argv, char **arg_list, t_list **a)
{
	if (argc == 2 && argv[1][0])
		freestr(arg_list);
	lstclear(a);
}
