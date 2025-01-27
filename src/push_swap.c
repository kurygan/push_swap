/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/01/27 22:12:33 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_list *int_list = NULL;
	char **arg_list;
	
	if (argc == 1)
		return(write(2, "please put an argument\n", 23), 1);
	else if (argc == 2)
		arg_list = ft_split(argv[1]);
	else
	{
		argv++;
		arg_list = argv;
	}
	create_list(arg_list, &int_list);
	while(int_list){
		printf("%d\n", int_list->i);
		int_list = int_list->next;
	}

	return (EXIT_SUCCESS);
}