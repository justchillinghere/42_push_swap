/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchitel <luchitel@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:14:45 by luchitel          #+#    #+#             */
/*   Updated: 2023/08/02 16:48:48 by luchitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

char** correct_str;
char** wrong_str;
int numStrings;

static void setup_argv()
{
    numStrings = 6;
    correct_str = (char**)malloc(numStrings * sizeof(char*));
    wrong_str = (char**)malloc(numStrings * sizeof(char*));

    if (!correct_str || !wrong_str) {
        printf("Memory allocation failed.\n");
        return;
    }

    correct_str[0] = ft_strdup("1");
    correct_str[1] = ft_strdup("2");
    correct_str[2] = ft_strdup("3");
    correct_str[3] = ft_strdup("-4");
    correct_str[4] = ft_strdup("-100");
    correct_str[5] = ft_strdup("0");

    wrong_str[0] = ft_strdup("1");
    wrong_str[1] = ft_strdup("2-3");
    wrong_str[2] = ft_strdup("3");
    wrong_str[3] = ft_strdup("");
    wrong_str[4] = ft_strdup("5");
    wrong_str[5] = ft_strdup("6");

}

static void teardown_argv()
{
	free(correct_str);
	free(wrong_str);
}

TestSuite(check_input, .init=setup_argv, .fini=teardown_argv);

Test(check_input, test_is_format_correct)
{
	// ft_printf("%d\n", is_format_correct(numStrings, strArray));
	cr_assert(eq(is_format_correct(numStrings, correct_str), OK));
	cr_assert(eq(is_format_correct(numStrings, wrong_str), ERROR));
}

Test(check_input, test_get_unique_values_array)
{
	int	correct_array[numStrings];
	int i = 0;
	int	*res_arr;

	while (i < numStrings)
	{
		correct_array[i] = ft_atoi(correct_str[i]);
		i++;
	}
	res_arr = get_unique_values_array(numStrings, correct_str);
	i = 0;
	while (i < numStrings)
	{
		cr_assert(eq(correct_array[i], res_arr[i]));
		i++;
	}

}

Test(check_input, test_atoi)
{
	int		value;
	char *inp;
	char*		val2;

	inp = ft_strdup("-214748");
	value = ft_atoi(inp);
	val2 = ft_itoa(value);
	if (ft_strncmp(inp, val2, 1) != 0)
		ft_printf("YYYYY\n");
	// ft_printf("%d\n", ft_atoi("21474836899"));
}