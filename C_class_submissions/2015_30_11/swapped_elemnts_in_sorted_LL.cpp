#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
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
void sort_list(struct node *head)
{
	struct node *temp, *temp1;
	int x;

	temp = head;
	while (temp->num < temp->next->num)
		temp = temp->next;
	
	x = temp->num;
	temp1 = temp->next;
	while (temp1->num < temp1->next->num)
		temp1 = temp1->next;

	temp->num = temp1->next->num;
	while (temp != temp1->next)
	{
		temp = temp->next;
	}
	temp->num = x;

}
void main()
{
	struct node* head, *temp;
	head = NULL;
	head = createnode(head, 17);
	head = createnode(head, 2);
	head = createnode(head, 3);
	head = createnode(head, 5);
	head = createnode(head, 6);
	head = createnode(head, 8);
	head = createnode(head, 10);
	head = createnode(head, 12);
	head = createnode(head, 1);

	printf("before sorting\n");
	temp = head;
	while (temp != NULL)
	{
		printf("%d\t", temp->num);
		temp = temp->next;
	}

	printf("\n");
	sort_list(head);
	printf("after sorting\n");
	while (head != NULL)
	{
		printf("%d\t", head->num);
		head = head->next;
	}
	_getch();

}