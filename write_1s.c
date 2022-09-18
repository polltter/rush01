#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	write_1s_top(char **output, char **input, int n);
int	write_1s_bottom(char **output, char **input, int n);
int	write_1s_left(char **output, char **input, int n);
int	write_1s_right(char **output, char **input, int n);
int	write_1s(char **output, char **input, int n);

int	write_1s_top(char **output, char **input, int n)
{
	int	in_column;

	(void) n;
	in_column = -1;
	while (++in_column < 4)
	{
		if (input[0][in_column] == '1')
		{
			if (output[0][in_column] == '0')
				output[0][in_column] = '4';

			else if (output[0][in_column] != '4')
			{
					
				return (0);
			}
		}
	}
	return (1);
}

int	write_1s_bottom(char **output, char **input, int n)
{
	int	in_column;

	(void) n;
	in_column = -1;
	while (++in_column < 4)
	{
		if (input[1][in_column] == '1')
		{
			if (output[3][in_column] == '0')
				output[3][in_column] = '4';
			else if (output[3][in_column] != '4')
				return (0);
		}
	}
	return (1);
}

int	write_1s_left(char **output, char **input, int n)
{
	int	in_column;

	(void) n;
	in_column = -1;
	while (++in_column < 4)
	{
		if (input[2][in_column] == '1')
		{
			if (output[in_column][0] == '0')
				output[in_column][0] = '4';
			else if (output[in_column][0] != '4')
				return (0);
		}
	}
	return (1);
}

int	write_1s_right(char **output, char **input, int n)
{
	int	in_column;

	(void) n;
	in_column = -1;
	while (++in_column < 4)
	{
		if (input[3][in_column] == '1')
		{
			if (output[in_column][3] == '0')
				output[in_column][3] = '4';
			else if (output[in_column][3] != '4')
				return (0);
		}
	}
	return (1);
}

int	write_1s(char **output, char **input, int n)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = write_1s_top(output, input, n);
	b = write_1s_bottom(output, input, n);
	c = write_1s_left(output, input, n);
	d = write_1s_right(output, input, n);
	return (a * b * c * d);
}