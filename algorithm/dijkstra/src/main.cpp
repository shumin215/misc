#include <iostream>
#include <queue>
#define NUM_VERTEX 8+1
#define MAX_W 9999999

using namespace std;

class Dijkstra
{
public:
    Dijkstra(): visited(false), w(0), prev(0) {}
    bool visited;
    int w;
    int prev;
};

int graph[NUM_VERTEX][NUM_VERTEX];
int dtable[NUM_VERTEX];
priority_queue<pair<int, int>> pq;

void initDtable(void)
{
    for (int i=0; i<NUM_VERTEX; i++) {
        dtable[i] = MAX_W;
    }
}

void updateDtable(int v)
{
    for (int i=1; i<NUM_VERTEX; i++) {
        if (graph[v][i] > 0) {
            if (dtable[i] > dtable[v] + graph[v][i]) {
                dtable[i] = dtable[v] + graph[v][i];
                pq.push(make_pair(dtable[i], i));
            }
        }
    }
}

void showDtable(void)
{
    for (int i=1; i<NUM_VERTEX; i++) {
        printf("%d: %d\n", i, dtable[i]);
    }
}

void doDijkstra(int v)
{
    pq.push({0, v});
    dtable[v] = 0;

    while(!pq.empty()) {
        int dist = pq.top().first;
        int next_v = pq.top().second;
        pq.pop();

        if (dtable[next_v] < dist)
            continue;

        updateDtable(next_v);
    }

    showDtable();
}

void addEdge(int src, int dst, int w, bool bidirection)
{
    graph[src][dst] = w;

    if (bidirection) {
        graph[dst][src] = w;
    }
}

int main()
{
    addEdge(1, 2, 3, false);
    addEdge(1, 4, 2, false);
    addEdge(2, 5, 9, false);
    addEdge(2, 6, 4, false);
    addEdge(3, 1, 7, false);
    addEdge(3, 4, 9, false);
    addEdge(4, 3, 25, false);
    addEdge(4, 7, 18, false);
    addEdge(5, 3, 10, false);
    addEdge(5, 8, 4, false);
    addEdge(6, 5, 8, false);
    addEdge(6, 7, 10, false);
    addEdge(7, 5, 7, false);
    addEdge(7, 6, 5, false);
    addEdge(7, 8, 3, false);
    addEdge(7, 3, 2, false);
    addEdge(8, 4, 3, false);

    initDtable();

    doDijkstra(1);

    return 0;
}


#ifdef ARRAY

#include <iostream>
#define NUM_VERTEX 8+1
#define MAX_W 9999999

using namespace std;

class Dijkstra
{
public:
    Dijkstra(): visited(false), w(0), prev(0) {}
    bool visited;
    int w;
    int prev;
};

int graph[NUM_VERTEX][NUM_VERTEX];
Dijkstra dtable[NUM_VERTEX];

void initDtable(void)
{
    for (int i=0; i<NUM_VERTEX; i++) {
        dtable[i].visited = false;
        dtable[i].w = MAX_W;
        dtable[i].prev = -1;
    }
}

void updateDtable(int v)
{
    for (int i=1; i<NUM_VERTEX; i++) {
        if (graph[v][i] > 0) {
            if (!dtable[i].visited && (dtable[i].w > dtable[v].w + graph[v][i])) {
                dtable[i].w = dtable[v].w + graph[v][i];
                dtable[i].prev = v;
            }
        }
    }
}

int findDijkstraNextV(void)
{
    int smallest_w = MAX_W;
    int smallest_v = -1;

    for (int i=1; i<=NUM_VERTEX; i++) {
        if (!dtable[i].visited && dtable[i].w < smallest_w) {
            smallest_w = dtable[i].w;
            smallest_v = i;
        }
    }

    return smallest_v;
}

void showDtable(void)
{
    for (int i=1; i<NUM_VERTEX; i++) {
        printf("%d: %d %d %d\n", i, dtable[i].visited, dtable[i].w, dtable[i].prev);
    }
}

void doDijkstra(int v)
{
    int next_v = -1;
    dtable[v].w = 0;

    while((next_v = findDijkstraNextV()) != -1) {
        dtable[next_v].visited = true;
        updateDtable(next_v);
    }

    showDtable();
}

void addEdge(int src, int dst, int w, bool bidirection)
{
    graph[src][dst] = w;

    if (bidirection) {
        graph[dst][src] = w;
    }
}

int main()
{
    addEdge(1, 2, 3, false);
    addEdge(1, 4, 2, false);
    addEdge(2, 5, 9, false);
    addEdge(2, 6, 4, false);
    addEdge(3, 1, 7, false);
    addEdge(3, 4, 9, false);
    addEdge(4, 3, 25, false);
    addEdge(4, 7, 18, false);
    addEdge(5, 3, 10, false);
    addEdge(5, 8, 4, false);
    addEdge(6, 5, 8, false);
    addEdge(6, 7, 10, false);
    addEdge(7, 5, 7, false);
    addEdge(7, 6, 5, false);
    addEdge(7, 8, 3, false);
    addEdge(7, 3, 2, false);
    addEdge(8, 4, 3, false);

    initDtable();

    doDijkstra(1);

    return 0;
}

#endif

#ifdef LINKED_LIST

#include <iostream>
#define NUM_VERTEX 8+1
#define MAX_W 9999999

using namespace std;

class Node
{
public:
    Node(int _v, int _w, Node *_next): v(_v), w(_w), next(_next) {}
    int v;
    int w;
    Node *next;
};

class Dijkstra
{
public:
    Dijkstra(): visited(false), w(0), prev(0) {}
    bool visited;
    int w;
    int prev;
};

Node *graph[NUM_VERTEX];
Dijkstra dtable[NUM_VERTEX];

void initDtable(void)
{
    for (int i=0; i<NUM_VERTEX; i++) {
        dtable[i].visited = false;
        dtable[i].w = MAX_W;
        dtable[i].prev = -1;
    }
}

void updateDtable(int v)
{
    Node *cur = graph[v];

    while(cur != nullptr) {
        if (!dtable[cur->v].visited && (dtable[cur->v].w > dtable[v].w + cur->w)) {
            dtable[cur->v].w = dtable[v].w + cur->w;
            dtable[cur->v].prev = v;
        }

        cur = cur->next;
    }
}

int findDijkstraNextV(void)
{
    int smallest_w = MAX_W;
    int smallest_v = -1;

    for (int i=1; i<=NUM_VERTEX; i++) {
        if (!dtable[i].visited && dtable[i].w < smallest_w) {
            smallest_w = dtable[i].w;
            smallest_v = i;
        }
    }

    return smallest_v;
}

void showDtable(void)
{
    for (int i=1; i<NUM_VERTEX; i++) {
        printf("%d: %d %d %d\n", i, dtable[i].visited, dtable[i].w, dtable[i].prev);
    }
}

void doDijkstra(int v)
{
    int next_v = -1;
    dtable[v].w = 0;

    while((next_v = findDijkstraNextV()) != -1) {
        dtable[next_v].visited = true;
        updateDtable(next_v);
    }

    showDtable();
}

void addEdge(int src, int dst, int w, bool bidirection)
{
    Node *new_node = new Node(dst, w, nullptr);
    Node *cur = graph[src];

    if (cur == nullptr) {
        graph[src] = new_node;
    } else {
        while(cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = new_node;
    }

    if (bidirection) {
        addEdge(dst, src, w, false);
    }
}

int main()
{
    addEdge(1, 2, 3, false);
    addEdge(1, 4, 2, false);
    addEdge(2, 5, 9, false);
    addEdge(2, 6, 4, false);
    addEdge(3, 1, 7, false);
    addEdge(3, 4, 9, false);
    addEdge(4, 3, 25, false);
    addEdge(4, 7, 18, false);
    addEdge(5, 3, 10, false);
    addEdge(5, 8, 4, false);
    addEdge(6, 5, 8, false);
    addEdge(6, 7, 10, false);
    addEdge(7, 5, 7, false);
    addEdge(7, 6, 5, false);
    addEdge(7, 8, 3, false);
    addEdge(7, 3, 2, false);
    addEdge(8, 4, 3, false);

    initDtable();

    doDijkstra(1);

    return 0;
}
#endif
