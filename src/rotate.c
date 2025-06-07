/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:52 by epascual          #+#    #+#             */
/*   Updated: 2025/06/07 17:18:31 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

void	rotate(t_list **x)
{
	t_list	*uno;
	t_list	*ulti;

	if (x == NULL || *x == NULL || ft_lstsize(*x) < 2)
		return ;
	uno = *x;
	ulti = ft_lstlast(*x);
	if (ulti == NULL)
		return ;
	*x = uno->next;
	if (*x == NULL)
		return ;
	ulti->next = uno;
	uno->next = NULL;
}

void	ra(t_list **x)
{
	rotate(x);
	ft_printf("ra\n");
}

void	rb(t_list **x)
{
	rotate(x);
	ft_printf("rb\n");
}

void	ft_free_pointstring(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	handle_arguments(int argc, char *argv[], t_parsed_args *data)
{
	data->is_split_allocated = 0;
	if (argc == 2)
	{
		data->str = ft_split(argv[1], ' ');
		data->wcnt = ft_wordcount(argv[1], ' ');
		data->nums = list_nums(data->str, data->wcnt);
		data->is_split_allocated = 1;
	}
	else
	{
		data->str = argv;
		data->wcnt = argc - 1;
		data->nums = list_nums(data->str + 1, data->wcnt);
	}
}
