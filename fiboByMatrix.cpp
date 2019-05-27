#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int **mul(int **A1, int **A2,int r1,int c1,int c2)
{
	int i, j, k, sum = 0;;
	int **A = (int**)malloc(r1 * sizeof(int*));

	for ( i = 0; i < 2; i++)
	{
		A[i] = (int*)malloc(c2 * sizeof(int));
	}
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c2; j++)
		{
			for (k = 0; k < c1; k++)
			{
				sum = sum + A1[i][k] * A2[k][j];
			}
			A[i][j] = sum;
			sum = 0;
		}
	}
	return A;
}


int **pow_n(int **A,int n)
{
	if (n == 1)
		return A;
	else
	{
		if (n % 2 == 0)
			return mul(pow_n(A, n / 2),pow_n(A, n / 2),2,2,2);
		else
		{
			return mul(A, mul(pow_n(A, n / 2), pow_n(A, n / 2),2,2,2),2,2,2);
		}
			
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	int **A = (int**)malloc(2 * sizeof(int*));

	for (int i = 0; i < 2; i++)
	{
		A[i] = (int*)malloc(2 * sizeof(int));
	}
	A[0][0] = 0;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 1;
	A = pow_n(A, n-1);
	int **A2 = (int**)malloc(2 * sizeof(int*));

	for (int i = 0; i < 2; i++)
	{
		A2[i] = (int*)malloc(sizeof(int));
	}
	A2[0][0] = 0;
	A2[1][0] = 1;
	A2 = mul(A, A2,2,2,1);
	printf("%d", A2[0][0]);
	//printf("%d", A2[1][0]);

	
}

/*int **A1 = (int**)malloc(2 * sizeof(int*));

for (int i = 0; i < 2; i++)
{
A1[i] = (int*)malloc(2 * sizeof(int));
}

A1[0][0] = 0;
A1[0][1] = 1;
A1[1][0] = 1;
A1[1][1] = 1;

int **A2 = (int**)malloc(2 * sizeof(int*));

for (int i = 0; i < 2; i++)
{
A2[i] = (int*)malloc(sizeof(int));
}
A2[0][1] = 0;
A2[1][0] = 1;*/