#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interval_tree.h"
#include "rbtree_augmented.h"
#include "interval_tree_generic.h"
#define INFO_NUM 6

struct interval_tree_node *
interval_tree_subtree_search( 
		struct interval_tree_node *, 
		unsigned long, unsigned long);
typedef struct {
	unsigned long start;
	unsigned long last;
	unsigned long __subtree_last;
	int color;
} NODE_INFO;

int __display(struct rb_node *temp, NODE_INFO (*array)[10], int *row, int *col) {
	struct interval_tree_node *info;
	if(temp == 0)
		return 0;

	++*row;
	__display(temp->rb_left, array, row, col);
	info = rb_entry(temp, struct interval_tree_node, rb);
	array[*row][(*col)].color = rb_color(temp);
	array[*row][(*col)].start = info->start;
	array[*row][(*col)].last = info->last;
	array[*row][(*col)++].__subtree_last = info->__subtree_last;
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
			if(a[i][j].__subtree_last) {
				if(a[i][j].color == RB_RED)
					printf("<%2lu,%2lu,%2lu>", a[i][j].start, a[i][j].last, a[i][j].__subtree_last);
				else
					printf("[%2lu,%2lu,%2lu]", a[i][j].start, a[i][j].last, a[i][j].__subtree_last);
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
	int i, index;
	struct interval_tree_node *temp;
	struct interval_tree_node nodes[INFO_NUM] = {
		{{0,},13,15,},
		{{0,},5,10,},
		{{0,},20,23,},
		{{0,},3,8,},
		{{0,},12,14,},
		{{0,},5,10,},
	};

	display(&root);
	for(i=0; i<INFO_NUM; i++) {
		interval_tree_insert(nodes+i, &root);
		display(&root);
	}
	temp = interval_tree_subtree_search( nodes, 12, 13 );
	if( temp )
		printf("%lu,%lu\n", temp->start, temp->last);
	else
		printf("%lu,%lu\n", 12UL, 16UL); 
	return 0;
}
