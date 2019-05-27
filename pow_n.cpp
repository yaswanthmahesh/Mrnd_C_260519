#include <stdio.h>

long long int pow(int a,int n)
{

	if (n = 0)
		return 1;

	else
		return (a*pow(a, n - 1));
}

int main()
{
	int a, n;
	scanf("%d%d", &a, &n);
	long long p = pow(a, n);
}