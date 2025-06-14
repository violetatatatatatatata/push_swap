/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:15:38 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/10 15:37:23 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   Inicializa y valida los datos de entrada, prepara los stacks, ejecuta el
   algoritmo de ordenación push_swap y limpia toda la memoria al final. Usa una
   estructura t_parsed_args para agrupar los datos de entrada.

   - handle_arguments()			Parsea los argumentos en números y strings
   - errata(nums, &s, code)		Muestra "Error"
   - init_stacks(nums, wcnt)	Inicializa los stacks con la entrada
   - checknum(wcnt, str)		Verifica que todos los valores sean válidos
   - norep(str, wcnt)			Comprueba que no haya números repetidos
   - selector(&s)				Ejecuta el algoritmo de radix
   - ft_free_pointstring(str)	Libera un array de strings (char **)
   - free_stacks(&s)			Libera los nodos de los stacks a y b
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	main(int argc, char *argv[])
{
	t_stacks		s;
	t_parsed_args	data;

	if (argc < 2)
		return (0);
	handle_arguments(argc, argv, &data);
	if (!data.nums)
		errata(NULL, NULL, 0);
	if (!checknum(data.wcnt, data.str) || !norep(data.str, data.wcnt))
		errata(data.nums, &s, 2);
	s = init_stacks(data.nums, data.wcnt);
	if (!s.a)
		errata(data.nums, &s, 2);
	selector(&s);
	if (data.is_split_allocated)
		ft_free_pointstring(data.str);
	free_stacks(&s);
	free(data.nums);
	return (0);
}

/*
   Libera la memoria de un array de strings (char **).
   - Itera sobre el array, liberando la memoria de cada
   string individual (tab[i]) y finalmente liberando la
   memoria del propio array (tab).
 */
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

/*
   Analiza argc y argv para preparar una lista de números
   enteros (nums) y una representación de cadena de esos
   números (str), junto con el conteo total de números (wcnt),
   almacenándolos en la estructura t_parsed_args. También
   establece un indicador (is_split_allocated) para saber si
   se asignó memoria dinámicamente para str.
 */
void	handle_arguments(int argc, char *argv[], t_parsed_args *data)
{
	char	*str;

	data->is_split_allocated = 0;
	if (argc == 2)
	{
		str = ft_strjoin("./program ", argv[1]);
		data->str = ft_split(str, ' ');
		free(str);
		data->wcnt = ft_wordcount(argv[1], ' ');
		data->nums = list_nums(data->str + 1, data->wcnt);
		data->is_split_allocated = 1;
	}
	else
	{
		data->str = argv;
		data->wcnt = argc - 1;
		data->nums = list_nums(data->str + 1, data->wcnt);
	}
}
