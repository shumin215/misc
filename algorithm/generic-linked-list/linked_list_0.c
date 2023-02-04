#include <stdio.h>
#include <stdlib.h>

typedef struct _node 
{
	int data;
	struct _node *next;
} NODE;

void insert_data(int _data, NODE *_node)
{
	NODE *temp;
	temp = malloc(sizeof(NODE));
	temp->data = _data;
	temp->next = _node->next;
	_node->next = temp;
	
}

void display(NODE *head)
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for(temp=head->next; temp; temp=temp->next)
		printf("->[%d]", temp->data);
	printf("->[tail]\n");
	getchar();
}

int main()
{
	NODE head0 = {0,};

	for(int i=0; i<5; i++)
		insert_data(i+1, &head0);

	display(&head0);
	return 0;
}
