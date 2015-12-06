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
void rec_rev(struct node **head)
{
	struct node *start, *rest;

	if (*head == NULL)
		return;
	start = *head;
	rest = start->next;

	if (rest == NULL)
		return;

	rec_rev(&rest);
	start->next->next = start;
	start->next = NULL;
	*head = rest;

}
void main()
{
	struct node* head, *temp, *prev;
	head = NULL;
	head = createnode(head, 2);
	head = createnode(head, 3);
	head = createnode(head, 90);
	head = createnode(head, 1);
	head = createnode(head, 4);
	head = createnode(head, 5);
	head = createnode(head, 6);
	head = createnode(head, 8);
	head = createnode(head, 0);

	printf("\nbefore reversal:");
	temp = head;
	while (temp != NULL)
	{
		printf("\ntemp_num:%d", temp->num);
		temp = temp->next;
	}
	temp = head->next;
	rec_rev(&head);
	printf("\nafter reversal:");
	temp = head;
	while (temp != NULL)
	{
		printf("\ntemp_num:%d", temp->num);
		temp = temp->next;
	}
	temp = head->next;

	_getch();

}