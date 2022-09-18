/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosvaldo <cosvaldo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:47:53 by mvenanci          #+#    #+#             */
/*   Updated: 2022/09/18 15:14:00 by cosvaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define N 4

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
int		write_1s_top(char **output, char **input, int n);
int		write_1s_bottom(char **output, char **input, int n);
int		write_1s_left(char **output, char **input, int n);
int		write_1s_right(char **output, char **input, int n);
int		write_1s(char **output, char **input, int n);
int		validate_input_comb(char **input);
int		validate_current_grid(char **output);
int		write_3s_top(char **output, char **input, int n);

void	print(int array[N][N]);
int		is_safe(int grid[N][N], int row, int col, int num);
int		solve_matrix(int grid[N][N], int row, int col);
int		ft_atoi(char *str);
int		test(void);

int	main(int argc, char **argv)
{
	char	**input;
	int		i;
	char	*only_numbers;
	char	**output;
	int		val;

	val = 0;
	i = -1;
	if (argc == 2 && valid_input(argv[1]))
	{
		only_numbers = rm_space(argv[1]);
		input = treat_input(only_numbers);
		output = generate_output(4);
		if (!validate_input_comb(input))
			write (1, "Error (1)\n", 11);
		if (!write_4s(output, input, 4))
		{
			write (1, "Error (2)\n", 11);
			while (input[++i])
				printf("%s\n", output[i]);
			return (0);
		}
		if (!write_1s(output, input, 4))
			write (1, "Error (3)\n", 11);
		if (!validate_current_grid(output))
			write (1, "Error (4)\n", 11);
		if (!write_3s_top(output, input, 4))
		{
			write (1, "Error", 5);
			return (0);
		}
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
	printf("%d %d %d %d\n",a ,b, c, d);
	return (a * b * c * d);
}
