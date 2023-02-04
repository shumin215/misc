#include <stdio.h>
#include <stdlib.h>

#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({ \
		const typeof( ((type *)0)->member ) *__mptr = (ptr); \
		(type *)( (char *)__mptr - offsetof(type,member));})

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};

void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {
	struct hlist_node *first = h->first;
	n->next = first;
	if(first)
		first->pprev = &n->next;
	h->first = n;
	n->pprev = &h->first;
}

//-------------- User Program --------------

#define HASH_MAX 8
#define PERSON_NUM 30

typedef struct {
	int id;
	struct hlist_node hash;
} PERSON;



int hash_func(int i) {
	return i % HASH_MAX;
}

void display(struct hlist_head *head) {
	system("clear");
	for(int i=0; i<HASH_MAX; i++) {
		struct hlist_node *temp;
		PERSON *p;
		printf("[%d]", i);
		for(temp = head[i].first; temp; temp=temp->next) {
			p = container_of(temp, PERSON, hash);
			printf("<->[%d]", p->id);
		}
		printf("\n");
	}
	getchar();
}

int main()
{
	struct hlist_head heads[HASH_MAX] = {0,};
	int hash_num, id;
	PERSON p[PERSON_NUM] = {0,};

	display(heads);
	for (int i=0; i<PERSON_NUM; i++) {
		id = 1000+i;
		p[i].id = id;
		hash_num = hash_func(id);
		hlist_add_head(&p[i].hash, &heads[hash_num]);
		display(heads);
	}
}
