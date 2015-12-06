//program to find the position of a loop in a looped (circulatr or p-shaped).
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
	int num;
	int bit;
	struct node *next;
};
struct node *createnode(struct node *head, int num)
{
	struct node *temp, *temp2;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->num = num;
	temp->next = NULL;
	temp->bit = 0;
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
void loop_pos(struct node *head)
{
	struct node *temp;// , *temp1, *temp2;
	temp = head;
	while (temp->bit != 0)
	{
		temp->bit = 1;
		temp = temp->next;
	}
	printf("node=%d,bit=%d", temp->num, temp->bit);
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

	temp = head;
	while (temp != NULL)
	{
		printf("\ntemp_num:%d\ttemp_bit:%d", temp->num, temp->bit);
		temp = temp->next;
	}
	temp = head->next;
	loop_pos(head);

	_getch();

}