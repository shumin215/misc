#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbtree.h"
#define INFO_NUM 3

#define RB_DECLARE_CALLBACKS(static, my_augment, INFO, node, int, augmented, my_compute)

typedef struct {
	char data[20];
	int	augmented;
	struct rb_node	node;
} INFO;

typedef struct {
	char data[20];
	int augmented;
	int color;
} NODE_INFO;

int my_compute (INFO *i) {
	int sum = 0;
	int child_augmented;
	if(i->node.rb_left) {
		child_augmented = rb_entry(i->node.rb_left, INFO, node)->augmented;
		sum += child_augmented;
	}
	if(i->node.rb_right) {
		child_augmented = rb_entry(i->node.rb_right, INFO, node)->augmented;
		sum += child_augmented;
	}
	return sum+1;
}

int rb_insert(struct rb_root *root, INFO *info) {
	struct rb_node **p = &root->rb_node;
	struct rb_node *parent = 0;
	INFO *temp;
	while(*p) {
		// Container_of
		parent = *p;
		temp = rb_entry( parent, INFO, node);

		if(strcmp(temp->data, info->data) > 0)
			p = &(*p)->rb_left;
		else if(strcmp(temp->data, info->data) < 0)
			p = &(*p)->rb_right;
		else
			return 0;
		temp->augmented++;
	}
	// Insert node
	rb_link_node(&info->node, parent, p);
	my_augment_propagate(parent, 0);
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
	array[*row][(*col)].augmented = info->augmented;
	strcpy(array[*row][(*col)++].data, info->data);
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
			if( strlen(a[i][j].data) > 0) {
				if(a[i][j].color == RB_RED)
					printf("<%6s,%d>", a[i][j].data, a[i][j].augmented);
				else
					printf("[%6s,%d]", a[i][j].data, a[i][j].augmented);
			}
			else
				printf("%10c", ' ');
		}
		printf("\n");
	}
	getchar();
}


int main() {
	struct rb_root root = {0};
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int i, index;
	INFO info[INFO_NUM] = {{"A",}, {"B",}, {"C",}};

	for(i=0; i<INFO_NUM; i++) {
//		info[i].data = a[i];
		rb_insert(&root, info+i);
		display(&root);
	}
	return 0;
}
