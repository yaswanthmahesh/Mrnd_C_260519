#include <stdio.h>

void printNum(int limit,int prev=0)
{
	if (limit == 1)
	{
		printf("%d ",prev/10 );
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			printNum(limit - 1, (prev + i) * 10);
		}
	}
}

int main()
{
	int n = 3;
	printNum(n, 0);
	getchar();
	return 0;
}