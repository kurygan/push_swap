/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/02 16:16:43 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	// t_list	*b;
	t_list	*temp;
	char	**arg_list;

	a = NULL;
	// b = NULL;
	arg_list = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putstr_fd("Put Good Number of Arguments", 2), 1);
	else if (argc == 2 && argv[1][0])
		arg_list = ft_split(argv[1]);
	else if (argc > 2)
		arg_list = ++argv;
	is_error(create_list(arg_list, &a));
	temp = a;
	while(temp)
	{
		printf("%d\n", temp->i);
		temp = temp->next;
	}
	
	if (argc == 2 && argv[1][0])
		freestr(arg_list);
	lstclear(&a);
	return (EXIT_SUCCESS);
}
