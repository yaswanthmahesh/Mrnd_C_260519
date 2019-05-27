#include <stdio.h>
#include <stdlib.h>

int sum_rec(int arr[],int n)
{
	if (n <= 0)
		return 0;
	else
		return (sum_rec(arr, n - 1) + arr[n]);
}

int main()
{
	int size, arr[];
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	int t = sum_rec(arr, size);
}