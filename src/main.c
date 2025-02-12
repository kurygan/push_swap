/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/12 01:15:36 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_list **list)
{
	t_list *temp = *list;
	while (temp && temp->next != *list)
	{
		printf("%d | ", temp->i);
		temp = temp->next;
	}
	if(temp)
		printf("%d | ", temp->i);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int total;
	char	**arg_list;

	a = NULL;
	b = NULL;
	arg_list = NULL;
	total = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putstr_fd("Put Good Number of Arguments", 2), 1);
	else if (argc == 2 && argv[1][0])
		arg_list = ft_split(argv[1]);
	else if (argc > 2)
		arg_list = ++argv;
	is_error(create_list(arg_list, &a));
	sort(&a, &b, &total);

	printf("a list: ");
	print_list(&a);
	printf("\n");
	printf("b list: ");
	print_list(&b);
	printf("\n");
	printf("Total operations: %d\n", total);
	
	if (argc == 2 && argv[1][0])
		freestr(arg_list);
	lstclear(&a);
	lstclear(&b);
	return (EXIT_SUCCESS);
}
