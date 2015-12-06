//program to add two linked lists and store the result in another list.

#include <stdio.h>
#include<malloc.h>
#include<conio.h>

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
void reverse(struct node **head)
{
	struct node *start, *rest;

	if (*head == NULL)
		return;
	start = *head;
	rest = start->next;

	if (rest == NULL)
		return;

	reverse(&rest);
	start->next->next = start;
	start->next = NULL;
	*head = rest;

}
void adder(struct node* head1,struct node *head2)
{
	int carry = 0, data = 0;
	struct node *result_head, *temp;
	if (head1 == NULL)
		result_head = head2;
	else if (head2 == NULL)
		result_head = head1;
	else
	{
		reverse(&head1);
		reverse(&head2);

		result_head = NULL;

		while (head1 != NULL && head2 != NULL)
		{

			data = (head1->num + head2->num) % 10 + carry;

			if ((head1->num + head2->num) / 10 != 0)
				carry = (head1->num + head2->num) / 10;
			else
				carry = 0;

			result_head = createnode(result_head, data);

			head1 = head1->next;
			head2 = head2->next;
		}
		if (head1 != NULL)
		{
			while (head1 != NULL)
			{
				data = head1->num + carry;
				result_head = createnode(result_head, data);
				head1 = head1->next;
				carry = 0;
			}
		}
		else if (head2 != NULL)
		{
			while (head2 != NULL)
			{
				data = head2->num + carry;
				result_head = createnode(result_head, data);
				head2 = head2->next;
				carry = 0;
			}
		}
		else
		{
			if (carry > 0)
			{
				result_head = createnode(result_head, carry);
			}
		}
		reverse(&result_head);
	}
	printf("\nsum:\n");
	while (result_head != NULL)
	{
		printf("%d", result_head->num);
		result_head = result_head->next;
	}
}
void main()
{
	struct node* head1,*head2, *temp;
	head1 = NULL;
	head2 = NULL;
	head1 = createnode(head1, 2);
	head1 = createnode(head1, 7);
	head1 = createnode(head1, 8);
	head1 = createnode(head1, 9);
	head2 = createnode(head2, 5);
	head2 = createnode(head2, 1);
	head2 = createnode(head2, 9);
	head2 = createnode(head2, 5);
	head2 = createnode(head2, 7);
	head2 = createnode(head2, 9);

	temp = head1;
	printf("\nlist1:\n");
	while (temp != NULL)
	{
		printf("%d", temp->num);
		temp = temp->next;
	}

	temp = head2;
	printf("\nlist2:\n");
	while (temp != NULL)
	{
		printf("%d", temp->num);
		temp = temp->next;
	}
	adder(head1,head2);
	
	_getch();

}