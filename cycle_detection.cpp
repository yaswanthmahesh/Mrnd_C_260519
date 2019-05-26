#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node*next;
};

void cycle_start(struct node *head)
{
	struct node *slow, *fast,*temp;
	int k = 0;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			k = 1;
		}
	}
	if (k == 1)
	{
		printf("cycle detected");
		temp = head;
		while (fast->next != temp)
		{
			fast = fast->next;
			temp = temp->next;
		}
		printf("cycle dected at %d", temp->data);
	}
	else
	{
		printf("no cycle detected");
	}
}

