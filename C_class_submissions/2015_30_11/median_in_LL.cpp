//program to find the median of a linked list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

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
void median(struct node *head)
{
	int count=0;
	struct node *temp;
	temp = head;
	while (temp!= NULL)
	{
		count++;
		temp = temp->next;
	}
	temp = head;
	count = count / 2;
	while (count > 0)
	{
		temp = temp->next;
		count--;
	}
	printf("\nmedian:%d",temp->num);
}
void main()
{
	struct node* head, *temp;
	head = NULL;
	head = createnode(head, 0);
	head = createnode(head, 1);
	head = createnode(head, 2);
	head = createnode(head, 3);
	head = createnode(head, 4);
	head = createnode(head, 5);
	head = createnode(head, 6);
	head = createnode(head, 7);
	//head = createnode(head, 8);
	temp = head;
	printf("\nlist:\n");
	while (temp != NULL)
	{
		printf("%d\t", temp->num);
		temp = temp->next;
	}
	median(head);
	
	_getch();

}