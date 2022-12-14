/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosvaldo <cosvaldo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:56:24 by cosvaldo          #+#    #+#             */
/*   Updated: 2022/09/18 21:28:10 by cosvaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 4

void	print(int array[N][N])
{
	int		i;
	int		j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			printf("%d", array[i][j]);
			if (j < N - 1)
				printf(" ");
		}
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
	if (solve_matrix(grid, 0, 0) == 1)
		print(grid);
	else
		write(1, "Error\n", 5);
	return (0);
}
