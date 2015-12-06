//method1

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
void merge(struct node *head1,struct node *head2)
{
	struct node *temp, *head;
	head = NULL;
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->num < head2->num)
		{
			head = createnode(head, head1->num);
			head1 = head1->next;
		}
		else
		{
			head = createnode(head, head2->num);
			head2 = head2->next;
		}
	}
	while (head1 != NULL)
	{
		head = createnode(head, head1->num);
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		head = createnode(head, head2->num);
		head2 = head2->next;
	}
	printf("\nafter merging:\n");
	while (head != NULL)
	{
		printf("%d->", head->num);
		head = head->next;
	}
}
void main()
{
	struct node* head1,*head2,*temp;
	head1 = NULL;
	head2 = NULL;
	head1 = createnode(head1, 1);
	head1 = createnode(head1, 3);
	head1 = createnode(head1, 5);
	head1 = createnode(head1, 7);
	head2 = createnode(head2, 2);
	head2 = createnode(head2, 4);
	head2 = createnode(head2, 6);
	head2 = createnode(head2, 8);
	head2 = createnode(head2, 10);
	printf("\nbefore merging\n");
	temp = head1;
	while (temp != NULL)
	{
		printf("%d->", temp->num);
		temp = temp->next;
	}
	printf("\n");
	temp = head2;
	while (temp != NULL)
	{
		printf("%d->", temp->num);
		temp = temp->next;
	}
	merge(head1,head2);

	_getch();

}