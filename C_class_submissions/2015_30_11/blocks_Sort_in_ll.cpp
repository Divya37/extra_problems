/*
Given a linked list which is in pattern like combination of ascending and descending. Sort it.(First all ascending numbers occur ,next all descending nums )
Note : min of descending part is greater than max of ascending
Ex: Input 1->2->7->20->15->10
Output 1->2->7->10->15->20
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node 
{
	int num;
	struct node *next;
};
struct node *createnode(struct node *head, int num)
{
	struct node *temp, *temp2;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->num = num;
	temp->next = NULL;
	if (head == NULL)
	{
		return temp;
	}
	else
	{
		temp2 = head;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
		return head;
	}
}
void blocks_sort(struct node *head,struct node *temp)
{
	struct node *temp1;
	int i, *arr;
	arr = (int *)malloc(sizeof(int) * 20);

	temp = head;
	if (temp == NULL)
		return;
	if (temp->next == NULL)
		return;

	while (temp->num < temp->next->num)
	{
		temp = temp->next;
		if (temp == NULL)
			break;
	}
	temp1 = temp;
	i = 0;
	while (temp1 != NULL)
	{
		if (temp1->next == NULL)
			break;
		if (temp1->num > temp1->next->num)
		{
			arr[i++] = temp1->num;
		
			if (temp1->next != NULL)
				temp1 = temp1->next;
			else
				break;
			
			arr[i] = temp1->num;
			
		}
		else
			break;
	}
	while (temp != temp1->next)
	{
		temp->num = arr[i];
		temp = temp->next;
		i--;
	}
	if (temp != NULL)
		blocks_sort(head, temp);
}
void main()
{
	struct node* head, *temp;
	head = NULL;
	head = createnode(head, 1);
	head = createnode(head, 2);
	head = createnode(head, 3);
	head = createnode(head, 5);
	head = createnode(head, 8);
	head = createnode(head, 7);
	head = createnode(head, 6);
	head = createnode(head, 9);
	head = createnode(head, 10);
	head = createnode(head, 13);
	head = createnode(head, 12);
	head = createnode(head, 11);

	printf("before sorting\n");
	temp = head;
	while (temp != NULL)
	{
		printf("%d\t", temp->num);
		temp = temp->next;
	}

	printf("\n");
	temp = head;

	blocks_sort(head, temp);
	printf("\nhead->num:%d", head->num);
	printf("after sorting\n");
	while (head != NULL)
	{
		printf("%d\t", head->num);
		head = head->next;
	}
	_getch();

}