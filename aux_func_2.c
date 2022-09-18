/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:43:47 by mvenanci          #+#    #+#             */
/*   Updated: 2022/09/18 13:38:54 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**generate_output(int n);
int		write_4s_columns_in_output_top(char **output, char **input, int n);
int		write_4s_rows_in_output_left(char **output, char **input, int n);
int		write_4s_columns_in_output_bottom(char **output, char **input, int n);
int		write_4s_rows_in_output_right(char **output, char **input, int n);

char	**generate_output(int n)
{
	int		i;
	char	**output;
	int		j;

	i = -1;
	output = (char **)malloc(sizeof(char *) * (n + 1));
	while (++i < n)
		output[i] = (char *)malloc(sizeof(char) * (n + 1));
	output[i] = 0;
	i = -1;
	while (output[++i])
	{
		j = -1;
		while (++j < n)
			output[i][j] = '0';
		output[i][j] = 0;
	}
	return (output);
}

int	write_4s_columns_in_output_top(char **output, char **input, int n)
{
	int	in_column;
	int	out_row;

	(void) n;
	in_column = -1;
	while (input[0][++in_column])
	{
		if ((input[0][in_column] == '4' && input[1][in_column] == '4') \
		|| (input[0][in_column] == '3' && input[1][in_column] == '3') \
		|| (input[0][in_column] == '1' && input[1][in_column] == '1'))
			return (0);
		else if (input[0][in_column] == '4')
		{
			out_row = -1;
			while (++out_row < 4)
			{
				if (output[out_row][in_column] == '0')
					output[out_row][in_column] = out_row + 1 + '0';
				else if (output[out_row][in_column] != out_row + 1 + '0')
					return (0);
			}
		}
	}
	return (1);
}

int	write_4s_rows_in_output_left(char **output, char **input, int n)
{
	int	in_column;
	int	out_column;

	(void) n;
	in_column = -1;
	while (++in_column < 4)
	{
		if ((input[2][in_column] == '4' && input[3][in_column] == '4') \
		|| (input[2][in_column] == '3' && input[3][in_column] == '3') \
		|| (input[2][in_column] == '1' && input[3][in_column] == '1'))
			return (0);
		else if (input[2][in_column] == '4')
		{
			out_column = -1;
			while (++out_column < 4)
			{
				if (output[in_column][out_column] == '0')
					output[in_column][out_column] = out_column + 1 + '0';
				else if (output[in_column][out_column] != out_column + 1 + '0')
					return (0);
			}
		}
	}
	return (1);
}

int	write_4s_columns_in_output_bottom(char **output, char **input, int n)
{
	int	in_column;
	int	out_row;

	(void) n;
	in_column = -1;
	while (++in_column < 4)
	{
		if (input[1][in_column] == '4')
		{
			out_row = 4;
			while (--out_row >= 0)
			{
				if (output[out_row][in_column] == '0')
					output[out_row][in_column] = -out_row + 4 + '0';
				else if (output[out_row][in_column] != out_row + 1 + '0')
					return (0);
			}
		}
	}
	return (1);
}

int	write_4s_rows_in_output_right(char **output, char **input, int n)
{
	int	in_column;
	int	out_column;

	(void) n;
	in_column = -1;
	while (++in_column < 4)
	{
		if (input[3][in_column] == '4')
		{
			out_column = 4;
			while (--out_column >= 0)
			{
				if (output[in_column][out_column] == '0' \
				|| output[in_column][out_column] == -out_column + 4 + '0')
					output[in_column][out_column] = -out_column + 4 + '0';
				else if (output[in_column][out_column] != out_column + 1 + '0')
					return (0);
			}
		}
	}
	return (1);
}
