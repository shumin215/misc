#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    Node(int _val, int _id): val(_val), id(_id) {}
    int val;
    int id;
};

struct cmp
{
    bool operator() (Node n1, Node n2) {
        if (n1.val == n2.val)
            return n1.id > n2.id;
        else
            return n1.val > n2.val;
    }
};

int main()
{
//    priority_queue<Node, vector<Node>, greater<Node>> gt_pq;
    priority_queue<Node, vector<Node>, cmp> gt_pq;
    priority_queue<pair<int, int>> ls_pq;

    gt_pq.push(Node(9,  1));
    gt_pq.push(Node(1,  2));
    gt_pq.push(Node(10, 3));
    gt_pq.push(Node(3,  4));
    gt_pq.push(Node(9,  5));

    ls_pq.push({9,  1});
    ls_pq.push({1,  2});
    ls_pq.push({10, 3});
    ls_pq.push({3,  4});
    ls_pq.push({9,  5});

    printf("########## Ascreasing Order Priority Queue ##########\n");
    while(!gt_pq.empty()) {
        Node node = gt_pq.top();
        gt_pq.pop();
        printf("[%d] %d\n", node.id, node.val);
    }

    printf("########## Descending Order Priority Queue ##########\n");
    while(!ls_pq.empty()) {
        pair<int, int> node = ls_pq.top();
        ls_pq.pop();
        printf("[%d] %d\n", node.second, node.first);
    }

    return 0;
}
