#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void transpose(int ** arr, int row, int col)
{
	int i, j;
	int ** a = (int **)malloc(col*sizeof(int **));
	for (int i = 0; i < col; i++)
	{
		a[i]= (int*)malloc(row*sizeof(int*));
	}
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			a[i][j] = arr[j][i];
		}
	}
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int row, col;
	scanf("%d", &row);
	scanf("%d", &col);
	int **arr = (int **)malloc(row*sizeof(int*));
	for (int i = 0; i < col; i++)
	{
		arr[i] = (int*)malloc(col*size0f(int));
	}

	for (int i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	transpose(arr, row, col);
}