#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *rev(struct node *head)
{
	struct node *prev = NULL;
	struct node *current = head;
	struct node *next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

struct node* createLL(int* s, int n)
{
	int i = 0;
	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	head->data = s[i];
	temp = head;
	for (i = 1; i <n; i++)
	{
		struct node* temp1 = (struct node*)malloc(sizeof(struct node));
		temp1->data = s[i];
		temp->next = temp1;
		temp1->next = NULL;
		temp = temp1;
	}
	return head;
}
void disp(struct node* l)
{
	struct node * tem = l;
	while (tem->next != NULL)
	{
		printf("%d->", tem->data);
		tem = tem->next;
	}
	printf("%d", tem->data);
}

struct node* add_linlist(struct node *num1, struct node* num2)
{
	struct node * temp,*temp1,*temp2,*head,*temp3;
	temp3 = (struct node*)malloc(sizeof(struct node));
	int count1 = 0, count2 = 0,t,i,j,carry=0,sun_l=0;

	temp = num1;
	while (temp != NULL)
	{
		temp = temp->next;
		count1++;
	}

	temp = num2;
	while (temp != NULL)
	{
		temp = temp->next;
		count2++;
	}

	if (count2 > count1)
	{
		t = count2;
		count2 = count1;
		count1 = t;
		temp1 = num2;
		temp2 = num1;
	}
	else
	{
		temp1 = num1;
		temp2 = num2;
	}

	struct node *num3 = (struct node *)malloc((count1 + 1)*sizeof(struct node));
	num3 = NULL;

	j = count2;

	for (i = count1; i > 0; i--)
	{
		temp1 = num1;
		temp2 = num2;
		int k = 0;
		while (k != i-1)
		{
			temp1 = temp1->next;
			k++;
		}

		if (j != 0)
		{
			k = 0;
			while (k != j-1)
			{
				temp2 = temp2->next;
				k++;
			}
			j--;
			sun_l = temp2->data;
		}
		else
		{
			sun_l = 0;
		}

		temp3->data = (carry + temp1->data + sun_l)%10;
		temp3->next = NULL;
		carry = (carry + temp1->data + sun_l) / 10;
		if (num3 == NULL)
		{
			num3 = temp3;
			head = num3;
		}
		else{
			num3->next = temp3;
			num3 = num3->next;
		}
		temp3 = (struct node*)malloc(sizeof(struct node));
	}
	if (carry == 1)
	{
		temp3->data = 1;
		temp3->next = NULL;
		num3->next = temp3;
	}

	//num3 = head;
	return head;
}



int main()
{
	int n1,n2, i;
	scanf("%d", &n1);
	int* arr1 = (int*)malloc(n1*sizeof(int));
	for (i = 0; i < n1; i++)
	{
		scanf("%d", &arr1[i]);
	}
	scanf("%d", &n2);
	int* arr2 = (int*)malloc(n2*sizeof(int));
	for (i = 0; i < n2; i++)
	{
		scanf("%d", &arr2[i]);
	}
	struct node * num1 = createLL(arr1, n1);
	disp(num1);
	struct node * num2 = createLL(arr2, n2);
	disp(num2);
	struct node *result = add_linlist(num1, num2);
	result = rev(result);
	disp(result);
}