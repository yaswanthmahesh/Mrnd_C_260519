#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

bool N(char arr[][3], int r, int c, char*str, int len)
{
	for (int i = r-1, j = c, l = 1; str[l] != '\0'; i--,l++)
	{
		if (arr[i][j] != str[l])
			return false;

	}
	return true;
}

bool NE(char arr[][3], int r, int c, char*str,int len)
{
	for (int i = r - 1, j = c + 1, l = 1; str[l] != '\0'; i--, j++,l++)
	{
		if (arr[i][j] != str[l])
			return false;

	}
	return true;
}

bool E(char arr[][3], int r, int c, char*str,int len)
{
	for (int i = r, j = c + 1, l = 1; str[l] != '\0'; j++, l++)
	{
		if (arr[i][j] != str[l])
			return false;
	
	}
	return true;
}

bool SE(char arr[][3], int r, int c, char*str,int len)
{
	for (int i = r + 1, j = c + 1, l = 1; str[i] != '\0'; i++, j++, l++)
	{
		if (arr[i][j] != str[l])
			return false;
	
	}
	return true;
}

bool S(char arr[][3], int r, int c, char*str,int len)
{
	for (int i = r + 1, j = c, l = 1; str[l] != '\0'; i++, l++)
	{
		if (arr[i][j] != str[l])
			return false;
	
	}
	return true;
}

bool SW(char arr[][3], int r, int c, char*str,int len)
{
	for (int i = r + 1, j = c - 1, l = 1; str[l] != '\0'; i++, j--, l++)
	{
		if (arr[i][j] != str[l])
			return false;
		
	}
	return true;
}

bool W(char arr[][3], int r, int c, char*str,int len)
{
	for (int i = r , j = c - 1, l = 1; str[l] != '\0'; j--, l++)
	{
		if (arr[i][j] != str[l])
			return false;

	}
	return true;
}

bool NW(char arr[][3], int r, int c, char*str,int len)
{
	for (int i = r - 1, j = c - 1, l = 1; str[l] != '\0'; i--, j--, l++)
	{
		if (arr[i][j] != str[l])
			return false;	
	}
	return true;
}

void str_search(char arr[][3],int row,int col,char*str,int len)
{
	int count = 0;
	int i = 0, j = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i >= len - 1 && j >= len - 1 && arr[i][j] == str[0])
			{
				if (NW(arr, i, j, str,len))
					count++;
			}
			if (i >= len - 1 && arr[i][j]==str[0])
			{
				if (N(arr, i, j, str,len))
					count++;
			}
			if (i >= len - 1 && j <= col - len && arr[i][j] == str[0])
			{
				if (NE(arr, i, j, str,len))
					count++;
			}
			if (j >= len - 1 && arr[i][j] == str[0])
			{
				if (W(arr, i, j, str,len))
					count++;
			}
			if (j <= col - len && arr[i][j] == str[0])
			{
				if (E(arr, i, j, str,len))
					count++;
			}
			if (i <= row - len && j >= len - 1 && arr[i][j] == str[0])
			{
				if (SW(arr, i, j, str,len))
					count++;
			}
			if (i <= row - len && arr[i][j] == str[0])
			{
				if (S(arr, i, j, str,len))
					count++;
			}
			if (i <= row - len && j <= col - len && arr[i][j] == str[0])
			{
				if (SE(arr, i, j, str,len))
					count++;
			}
		}
	}
	printf("%d", count);
}


int main()
{
	char **A = (char**)malloc(3 * sizeof(char*));

	for (int i = 0; i < 3; i++)
	{
		A[i] = (char*)malloc(3 * sizeof(char));
	}
	char A [][3]= { { 'a', 'b', 'c' }, {'b','b','c'} ,{'c','a','c'} };
	char* str = (char*)malloc(4 * sizeof(char));
	str = "abc";
	str_search(A, 3, 3, str,3);
	getchar();
}