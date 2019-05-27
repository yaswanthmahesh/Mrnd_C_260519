#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int fib_rec(int n)
{
	static map<long int, long int> m;
	int a = 0, b = 1;
	if (n == 1 || n==0)
		return 1;

	else
	{
		if (m[n - 1]!=0 && m[n - 2]!=0)
			return m[n - 1] + m[n - 2];

		else if (m[n - 1]==0 && m[n - 2]!=0)
			m[n - 1] = fib_rec(n - 1);

		else if (m[n - 2]==0 && m[n - 1]!=0)
			m[n - 2] = fib_rec(n - 2);

		else
		{
			m[n - 1] = fib_rec(n - 1);
			m[n - 2] = fib_rec(n - 2);
		}
		return m[n-1] + m[n - 2];
	}
}

int main()
{
	int n=5;
	n = fib_rec(n);
	return 0;
}