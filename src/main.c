/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:15:38 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/07 18:08:12 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Inicializa y valida los datos de entrada, prepara los stacks, ejecuta el
algoritmo de ordenación push_swap y limpia toda la memoria al final. Usa una
estructura t_parsed_args para agrupar los datos de entrada.

- handle_arguments()			Parsea los argumentos en números y strings
- errata(nums, &s, code)		Muestra "Error"
- init_stacks(nums, wcnt)		Inicializa los stacks con la entrada
- checknum(wcnt, str)			Verifica que todos los valores sean válidos
- norep(str, wcnt)				Comprueba que no haya números repetidos
- selector(&s)					Ejecuta el algoritmo de radix
- ft_free_pointstring(str)		Libera un array de strings (char **)
- free_stacks(&s)				Libera los nodos de los stacks a y b
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main(int argc, char *argv[])
{
    t_stacks        s;
    t_parsed_args   data;

    if (argc < 2)
        return (0);
    handle_arguments(argc, argv, &data);
    if (!data.nums)
        errata(NULL, NULL, 0);
    s = init_stacks(data.nums, data.wcnt);
    if (!s.a)
        errata(data.nums, &s, 2);
    if (!checknum(data.wcnt, data.str) || !norep(data.str, data.wcnt))
        errata(data.nums, &s, 2);
    selector(&s);
    if (data.is_split_allocated)
        ft_free_pointstring(data.str);
    free_stacks(&s);
    free(data.nums);
    return (0);
}
