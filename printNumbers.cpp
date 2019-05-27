#include <stdio.h>

int numLen(int n, int p)
{
	int d = p;
	int count = 0;
	while (d >= 10)
	{
		count++;
		d = d / 10;
	}
	count++;
	if (count < n)
		return 1;
	else 
		return 0;
}*/

/*void printNum(int n,int i)
{
	if (numLen(n, i))
	{
		printf("%d", i);
		i++;
	}
}

int main()
{
	int n=3;
	printNum(n, 1);
	getchar();
	return 0;
}