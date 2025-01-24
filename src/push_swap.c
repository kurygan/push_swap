/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/01/15 22:22:42 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
	t_list *int_list = NULL;
	char **arg_list = NULL;
	
	if (argc == 1)
		return(write(2, "wrong amount of arguments\n", 26), 0);
	if (argc == 2)
	{
		arg_list = ft_split(argv[1]);
		create_list(arg_list, int_list);
	}
	while(*arg_list)
		printf("%s\n", *arg_list++);

	return (EXIT_SUCCESS);
}