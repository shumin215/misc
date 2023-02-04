// Double Linked List
#include <stdio.h>
#include <stdlib.h>
#define FIFO_DEPTH 10

typedef struct _node 
{
	int data;
	struct _node *next;
	struct _node *prev;
} NODE;

void insert_data(NODE *_temp, NODE *_node)
{
	_temp->next = _node->next;
	_temp->prev = _node;
	_node->next = _temp;
	_temp->next->prev = temp;
}

void display(NODE *head)
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for(temp=head->next; temp != head; temp=temp->next)
		printf("->[%d]", temp->data);
	printf("->[head]\n");
	getchar();
}

void reverse(NODE *head)
{
	NODE *prev = head;
	NODE *curr = prev->next;
	NODE *next;
	while(curr != head) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	curr->next = prev;
}

int main()
{
	NODE head0 = {0,&head0, &head0};
	NODE temps[FIFO_DEPTH];

	for(int i=0; i<FIFO_DEPTH; i++)
	{
		temps[i].data = i+1;
		insert_data(temps+i, &head0);
		display(&head0);
	}

	// Reverse
	reverse(&head0);
	display(&head0);
	
	return 0;
}
