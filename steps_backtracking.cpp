#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void noOfWaysToClimb(int steps,int k)
{
	static int count = 0,count1=0;
	if (steps == 0)
	{
		count++;
	}
	else
	{
		for (int i = 1; i <= k; i++)
		{
			if (steps - i < 0)
			{
				count1--;
				return;
			}
			count1++;
			noOfWaysToClimb(steps - i,k);
		}
		if (count1==0)
		    printf("%d", count);
	}
	count1--;

}

int main()
{
	int n, k, res;
	scanf("%d", &n);
	scanf("%d", &k);
	noOfWaysToClimb(n,k);
}