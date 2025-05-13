/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:15:38 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/13 16:47:04 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	- Verifica si hay suficientes argumentos (argc < 2).
		Si no, termina el programa.
	- Comprueba que los argumentos sean números válidos (checknum) y que no
	haya duplicados (norep).
		Si falla, imprime "Error" y termina.
	- Calcula el tamaño de la lista (size = argc - 1).
	- Convierte los argumentos en una lista de números enteros (list_nums).
		Si falla, imprime "Error" y termina.
	- Inicializa las pilas (init_stacks) con los números y su tamaño.
		Si falla, imprime "Error", libera la memoria de los números y termina.
	- Llama a selector, que probablemente contiene la lógica principal.
	- Libera la memoria de la lista de números y las pilas antes de salir.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	main(int argc, char *argv[])
{
	t_stacks	s;
	int			*nums;
	int			size;

	if (argc < 2)
		return (0);
	if (!checknum(argc, argv) || !norep(argv, argc))
		return (ft_printf("Error 1\n"), 1);
	size = argc - 1;
	nums = list_nums(argv[1]);
	if (!nums)
		return (ft_printf("Error 2\n"), 1);
	s = init_stacks(nums, size);
	if (!s.a)
	{
		ft_printf("Error 3\n");
		free(nums);
		return (1);
	}
	selector(&s);
	free(nums);
	free_stacks(&s);
	return (0);
}
