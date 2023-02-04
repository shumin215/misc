#include <iostream>
#include <vector>
#include <algorithm>

#define NUM_EDGES 8
#define NUM_VERTEX 5

using namespace std;

class Edge
{
public:
    Edge(int _src, int _dst, int _w): src(_src), dst(_dst), w(_w) {}
    int src;
    int dst;
    int w;
};

vector<Edge> edge_list;
int group_table[NUM_VERTEX];
int total_weight;

bool cmp(Edge e1, Edge e2)
{
    if (e1.w == e2.w)
        return e1.src < e2.src;
    else
        return e1.w < e2.w;
}

void addEdge(int _s, int _d, int _w, int _bidirection)
{
    edge_list.push_back(Edge(_s, _d, _w));
}

void updateGroupTable(int _s, int _d)
{
    int s_group = group_table[_s];
    int d_group = group_table[_d];
    int smaller = (s_group < d_group) ? s_group : d_group;
    int bigger = (s_group < d_group) ? d_group : s_group;

    for (int i=0; i<NUM_VERTEX; i++) {
        if (group_table[i] == bigger)
            group_table[i] = smaller;
    }
}

void doMST(void)
{
    int edge_num = 0;
    for (int i=0; i<NUM_EDGES; i++) {
        // Compare group number
        if (group_table[edge_list[i].src] != group_table[edge_list[i].dst]) {
            printf("[%d]---(%d)---[%d]\n", edge_list[i].src, edge_list[i].w, edge_list[i].dst);
            edge_num++;
            total_weight += edge_list[i].w;
            
            if (edge_num == NUM_VERTEX + 1) {
                return;
            }

            updateGroupTable(edge_list[i].src, edge_list[i].dst);
        }
    }
}

int main(void)
{
    for (int i=0; i<NUM_VERTEX; i++)
        group_table[i] = i;

    addEdge(0, 1, 1, true);
    addEdge(0, 2, 3, true);
    addEdge(0, 4, 5, true);
    addEdge(1, 2, 2, true);
    addEdge(1, 4, 4, true);
    addEdge(2, 4, 6, true);
    addEdge(2, 3, 7, true);
    addEdge(3, 4, 8, true);

    sort(edge_list.begin(), edge_list.end(), cmp);

    doMST();

    printf("Total weight: %d\n", total_weight);

    return 0;
}
