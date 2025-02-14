/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:00:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/14 15:29:04 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	verif_sorted(t_list **a)
{
	t_list *temp_a;

	temp_a = *a;
	while (1)
	{
		if (temp_a->i > temp_a->next->i && temp_a->next != *a)
			return (false);
		if (temp_a->next == *a)
			break ;
		temp_a = temp_a->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	//t_list *temp_a;
	bool	list_error;
	int		total;
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
	list_error = create_list(arg_list, &a);
	if (list_error || verif_sorted(&a))
	{
		free_all(argc, argv, arg_list, &a);
		is_error(list_error);
	}
	sort(&a, &b, &total);
	//temp_a = a;
	//whvile (1)
	//{
	//	printf("%d | ", temp_a->i);
	//	if (temp_a->next == a)
	//		break ;
	//	temp_a = temp_a->next;
	//}
	free_all(argc, argv, arg_list, &a);
	return (EXIT_SUCCESS);
}
