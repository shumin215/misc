#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"
#define INFO_NUM 8

typedef struct {
	int data;
	struct rb_node node;
} INFO;

typedef struct {
	int data;
	int color;
} NODE_INFO;

int rb_insert(struct rb_root *root, INFO *info) {
	struct rb_node **p = &root->rb_node;
	struct rb_node *parent = 0;
	INFO *temp;
	while(*p) {
		// Container_of
		parent = *p;
		temp = rb_entry( parent, INFO, node);

		if(info->data < temp->data)
			p = &(*p)->rb_left;
		else if(info->data > temp->data)
			p = &(*p)->rb_right;
		else
			return 0;
	}
	// Insert node
	rb_link_node(&info->node, parent, p);
	// Balance tree
	rb_insert_color(&info->node, root);

	return 1;
}

int __display(struct rb_node *temp, NODE_INFO (*array)[10], int *row, int *col) {
	INFO *info;
	if(temp == 0)
		return 0;

	++*row;
	__display(temp->rb_left, array, row, col);
	info = rb_entry(temp, INFO, node);
	array[*row][(*col)].color = temp->rb_color;
	array[*row][(*col)++].data = info->data;
	__display(temp->rb_right, array, row, col);
	--*row;
}

void display(struct rb_root *root) {
	int row = -1;
	int col = 0;
	NODE_INFO a[10][10] = {0,};
	__display(root->rb_node, a, &row, &col);
	
	system("clear");
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			if(a[i][j].data) {
				if(a[i][j].color == RB_RED)
					printf("<%2d>", a[i][j].data);
				else
					printf("[%2d]", a[i][j].data);
			}
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	getchar();
}

int main() {
	struct rb_root root = {0};
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int i;
	INFO info[INFO_NUM];

	display(&root);
	for(i=0; i<INFO_NUM; i++) {
		info[i].data = a[i];
		rb_insert(&root, info+i);
		display(&root);
	}

	return 0;
}
