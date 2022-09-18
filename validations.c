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
	int	row;
	int	column;
	int	i;

	row = -1;
	while (++row < 4)
	{
		column = -1;
		while (++column < 4)
		{
			i = -1;
			while (++i < 4)
			{
				if ((output[row][column] == output[row][i] \
				|| output[row][column] == output[i][column]) \
				&& (i != row && i != column)\
				&& output[row][column] != '0')
					return (0);
			}
			
		}
	}
	return (1);
}