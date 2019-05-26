#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
char * numtostr(int num)
{
	int d = 0, count = 0;
	d = num;
	while (d > 10)
	{
		d = d / 10;
		count++;
	}
	count++;
	char * str1 = (char*)malloc(count + 1 * sizeof(char));
	int i = count - 1,p;
	d = num;
	while (d>0)
	{
		p = d % 10;
		str1[i] = p + 48;
		i--;
		d = d / 10;
	}
	str1[count] = '\0';
	return str1;
}

int numtolen(int n)
{
	int d = 0, count = 0;
	d = n;
	while (d > 10)
	{
		d = d / 10;
		count++;
	}
	count++;
	return count;
}

void string_compp(char *str)
{
	int i = 0, j = 0,count=0;
	char b;
	char *str2;
	while (str[i] != '\0')
	{
		i++;
	}
	int p = i;
	//char *str1 = (char*)malloc(i*sizeof(char));
	for (i = 0; i < p; i++)
	{
		b = str[i];
		if (i == 0)
		{
			str[j] = str[i];
			j++;
			count++;
		}
		else
		{
			if (str[i - 1] == b)
				count++;
			else
			{
				str2 = numtostr(count);
				int a = numtolen(count);
				if (count != 1)
				{
					int k = 0;
					while (str2[k] != '\0')
					{
						str[j] = str2[k];
						j++; k++;
					}
				}
				if (b == '\0')
				{
					str[j] = '\0';
					break;
				}
				else
				{
					str[j] = b;
					count = 1;
					j++;
				}
			}
		}
	}
}

int main()
{
	int n, i = 0;
	char *str = (char*)malloc(1000 * sizeof(char));
	scanf("%s", str);

	while (str[i] != '\0')
		i++;
	//char *str1 = (char*)malloc((i+1)*sizeof(char));
	string_compp(str);
	printf("%s", str);
	return 0;

}
