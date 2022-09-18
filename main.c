/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:47:53 by mvenanci          #+#    #+#             */
/*   Updated: 2022/09/18 13:57:45 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		valid_input(char *str);
int		is_num(char c);
int		is_space(char c);
char	**treat_input(char *str);
char	*rm_space(char *str);
char	**generate_output(int n);
int		write_4s_columns_in_output_top(char **output, char **input, int n);
int		write_4s_rows_in_output_left(char **output, char **input, int n);
int		write_4s_columns_in_output_bottom(char **output, char **input, int n);
int		write_4s_rows_in_output_right(char **output, char **input, int n);
int		write_4s(char **output, char **input, int n);

int	main(int argc, char **argv)
{
	char	**input;
	int		i;
	char	*only_numbers;
	char	**output;

	i = -1;
	if (argc == 2 && valid_input(argv[1]))
	{
		only_numbers = rm_space(argv[1]);
		input = treat_input(only_numbers);
		output = generate_output(4);
		if (!write_4s(output, input, 4))
		{
			write (1, "Error", 5);
			return (0);
		}
		while (input[++i])
			printf("%s\n", output[i]);
	}
	else
		write (1, "Error", 5);
	return (0);
}

int	write_4s(char **output, char **input, int n)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = write_4s_columns_in_output_top(output, input, n);
	b = write_4s_rows_in_output_left(output, input, n);
	c = write_4s_columns_in_output_bottom(output, input, n);
	d = write_4s_rows_in_output_right(output, input, 4);
	return (a * b * c * d);
}

