/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosvaldo <cosvaldo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:56:24 by cosvaldo          #+#    #+#             */
/*   Updated: 2022/09/18 16:03:42 by cosvaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define N 4

char	**generate_output(int n);

void	print(int array[N][N])
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			printf("%d ", array[i][j]);
		printf("\n");
	}
}

int	is_safe(int grid[N][N], int row, int col, int num)
{
	int	x;

	x = -1;
	while (++x <= (N - 1))
		if (grid[row][x] == num)
			return (0);
	x = -1;
	while (++x <= (N - 1))
		if (grid[x][col] == num)
			return (0);
	return (1);
}

int	solve_matrix(int grid[N][N], int row, int col)
{
	int	num;

	if ((row == (N - 1)) && (col == N))
		return (1);
	if (col == N)
	{
		row++;
		col = 0;
	}
	if (grid[row][col] > 0)
		return (solve_matrix(grid, row, col + 1));
	num = 0;
	while (++num <= N)
	{
		if (is_safe(grid, row, col, num) == 1)
		{
			grid[row][col] = num;
			if (solve_matrix(grid, row, col + 1) == 1)
				return (1);
		}
		grid[row][col] = 0;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	length;
	int	count;
	int	num;

	length = 0;
	count = 0;
	num = 0;
	while (str[length])
		length++;
	while (count < N)
	{
		if (str[count] >= 48 && str[count] <= 57)
		{
			while ((str[count] >= 48) && (str[count] <= 57))
			{
				num = (10 * num - (str[count] - 48));
				count++;
			}
			break ;
		}
		count++;
	}
	return (num);
}

int	c_output(char **output)
{
	int	grid[N][N];
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			grid[i][j] = output[i][j] - '0';	
		}
	}
/*	 = {\
		{1, 2, 3, 4}, \
		{2, 3, 4, 0}, \
		{3, 4, 0, 0}, \
		{4, 0, 0, 0} \
		};
*/
	if (solve_matrix(grid, 0, 0) == 1)
		print(grid);
	else
		printf("Error\n");
	return (0);
}
