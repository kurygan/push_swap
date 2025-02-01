/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/01 04:08:48 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_list *int_list = NULL;
	char **arg_list = NULL;
	
	if (argc == 1)
		return(write(2, "please put an argument\n", 23), 1);
	else if (argc == 2 && argv[1][0])
		arg_list = ft_split(argv[1]);
	else if (argc > 2)
	{
		argv++;
		arg_list = argv;
	}
	else
		return (1);
	is_error(create_list(arg_list, &int_list));
	
	if (argc == 2 && argv[1][0])
		freestr(arg_list);
	lstclear(&int_list);

	return (EXIT_SUCCESS);
}