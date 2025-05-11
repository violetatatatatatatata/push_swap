/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:15:38 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/11 15:47:06 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*Parece ser que sa = sb, pa = pb, ra = rb, rra = rrb
 * Has de utilizar el stack b como si fuera el temporal?
 * No usar atoi por si letras intercaladas.
 * Necesitas una util que cuente el tamano de los arrays
 * */

int	main(int argc, char *argv[])
{
	t_stacks	s;
	int			*nums;
	int			size;

	if (argc < 2)
		return (0);
	if (checknum(argc, argv) == 0 || norep(argv, argc) == 0)
	{
		ft_printf("Errorini argumentiini\n");
		return (1);
	}
	size = 0;
	nums = list_nums(*argv);
	if (!nums)
	{
		ft_printf("Error 536\n");
		return (1);
	}
	s = init_stacks(nums, size);
	if (!s.a)
	{
		ft_printf("Error nostack\n");
		free(nums);
		return (1);
	}
	if (checkorder(s.a))
		ft_printf("Ordenado\n");
	else
		ft_printf("No ordenado\n");
	ft_printf("Imprime a:\n");
	ft_printlist(s.a);
	selector(&s);
	free_stacks(&s);
	return (0);
}
