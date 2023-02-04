#include <stdio.h>
#include <stdlib.h>

typedef struct _node 
{
	int data;
	struct _node *next;
} NODE;

void insert_data(NODE *_temp, NODE *_node)
{
	_temp->next = _node->next;
	_node->next = _temp;
}

void display(NODE *head, NODE *tail)
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for(temp=head->next; temp != tail; temp=temp->next)
		printf("->[%d]", temp->data);
	printf("->[tail]\n");
	getchar();
}

int main()
{
	NODE tail = {0,&tail};
	NODE head0 = {0,&tail};
	NODE temps[5];

	for(int i=0; i<5; i++)
	{
		temps[i].data = i+1;
		display(&head0, &tail);
		insert_data(temps+i, &head0);
	}

//	display(&head0);
	return 0;
}
