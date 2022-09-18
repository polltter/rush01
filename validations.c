#include <stdio.h>

int	validate_input_comb(char **input);
int	validate_current_grid(char **output);

int	validate_input_comb(char **input)
{
	int	column;

	column = -1;
	while (++column < 4)
	{
		if (input[0][column] == '4' && input[1][column] != '1')
			return (0);
		if (input[0][column] == '3' && (input[1][column] != '1' && input[1][column] != '2'))
			return (0);
		if (input[0][column] == '2' && input[1][column] == '4')
			return (0);
		if (input[2][column] == '4' && input[3][column] != '1')
			return (0);
		if (input[2][column] == '3' && (input[3][column] != '1' && input[1][column] != '2'))
			return (0);
		if (input[2][column] == '2' && input[3][column] == '4')
			return (0);
	}
	return (1);
}

int	validate_current_grid(char **output)
{
	int	diagonal;
	int	i;

	diagonal = -1;
	while (++diagonal < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if ( i == diagonal)
				;
			else if ((output[diagonal][diagonal] == output[diagonal][i] \
			|| output[diagonal][diagonal] == output[i][diagonal]) \
			&& output[diagonal][diagonal] != '0')
				return (0);
		}
	}
	return (1);
}