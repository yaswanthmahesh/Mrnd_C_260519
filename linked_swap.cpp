#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node* createLL(int* s,int n)
{
	int i = 0;
	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	head->data = s[i] ;
	temp = head;
	for (i = 1;i <n; i++)
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



struct node * rev(struct node * head, int k)
{
	struct node *t1, *t2, *t3;
	t1 = NULL;
	t2 = head;
	t3 = head;
	int i = 0;
	while (i < k)
	{
		if (i == 2)
		{
			t2->next = t1;
			i++;
		}
		else
		{
			t3 = t2->next;
			t2->next = t1;
			t1 = t2;
			t2 = t3;
			i++;
		}
	}
	return t2;
}

struct node *foo(struct node * head, int k)
{
	struct node *temp = head;
	struct node *temp2, *temp3, *temp4;
	int count = 0, l = 0;
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	count++;
	if (head == NULL)
		return NULL;
	if (count < k)
		return head;
	else if (count == k)
		return rev(head, k);
	else
	{
		int p = 0;
		temp = head;
		for (int i = 0; i < count; i++)
		{
			if (i%k == 0 && i / k == 1)
			{
				temp2 = head;
				head = rev(head, k);
				temp3 = temp;
				temp4 = temp2;
			}
			else if (i%k == 0 && i / k != 1 && i!=0)
			{
				temp4->next = rev(temp3, k);
				temp4 = temp3;
				temp3 = temp;
			}
			if (i + 1 == count || i + 2 == count && i%k == 0)
			{
				temp4->next = temp;
				return head;
			}
			else if (i + 3 == count && i%k == 0)
			{
				temp4->next = rev(temp, k);
				return head;
			}
			temp = temp->next;
		}
	}
}

int main()
{
	int n,i;
	scanf("%d", &n);
	int* arr = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	struct node * head = createLL(arr, n);
	head = foo(head, 3);
	disp(head);
	int k;
	scanf("%d", &k);
}
