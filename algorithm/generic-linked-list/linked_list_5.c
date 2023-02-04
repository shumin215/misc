// Double Linked List
#include <stdio.h>
#include <stdlib.h>
#define FIFO_DEPTH 2

/*
typedef struct _node 
{
	int data;
	struct _node *next;
	struct _node *prev;
} NODE;
*/

typedef struct _node 
{
	void *data;
	struct _node *next;
	struct _node *prev;
} NODE;

typedef struct _sawon {
	char name[20];
} SAWON;

void __insert_data(NODE *_temp, NODE *_prev, NODE *_next)
{
	_temp->next = _next;
	_prev->next = _temp;
	_temp->prev = _prev;
	_next->prev = _temp;
}

void insert_front(NODE *_temp, NODE *_head) {
	__insert_data(_temp, _head, _head->next);
}

void insert_back(NODE *_temp, NODE *_head) {
	__insert_data(_temp, _head->prev, _head);
}

void display(NODE *head)
{
	NODE *temp;
	SAWON *s;
	system("clear");
	printf("[head]");
	for(temp=head->next; temp != head; temp=temp->next) {
		s = (SAWON*) temp->data;
		printf("<->[%s]", s->name);
	}
	printf("<->[head]\n");
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
	SAWON s[FIFO_DEPTH] = {{"Jason"}, {"Tommy"}};

	display(&head0);
	for(int i=0; i<FIFO_DEPTH; i++)
	{
		temps[i].data = &s[i];
		insert_front(temps+i, &head0);
		display(&head0);
	}

	// Reverse
//	reverse(&head0);
//	display(&head0);
	
	return 0;
}
