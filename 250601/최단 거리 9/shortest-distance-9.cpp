#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define MAX_N 1001

int n, m;
int A, B;

struct Node
{
  int idx,dist;
  Node *next;  
  friend bool operator < (const Node n1, const Node n2)
  {
    return n1.dist > n2.dist;
  }
};

Node* head[MAX_N];
int dist[MAX_N];
int path[MAX_N];

void print_graph()
{

    for(int i = 1; i<=n; i++)
    {
        Node* cur = head[i];
        printf("%d node : ",i);
        while(cur)
        {
            printf("[%d,%d] ",cur->idx,cur->dist);
            cur= cur->next;
        }
        printf("\n");
        
    }
}

void print_dist_path()
{
    cout << "dist\n";
    for(int i = 1; i<=n ;i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";

    cout << "path\n";
    for(int i = 1; i<=n ;i++)
    {
        cout << path[i] << " ";
    }
    cout << "\n";


}

void make_graph(int from,int to,int weight)
{
    Node* newnode = new Node();
    newnode->idx = to;
    newnode->dist = weight;
    newnode->next = head[from];
    head[from] = newnode;

    Node* newnode2 = new Node();
    newnode2->idx = from;
    newnode2->dist = weight;
    newnode2->next = head[to];
    head[to] = newnode2;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from,to,weight;
        cin >> from >> to >> weight;
        
        make_graph(from,to,weight);
    }

    cin >> A >> B;

    // Please write your code here.

    for(int i =1;i<=n;i++)
        dist[i] = 0x7fff0000;
    dist[A] = 0;

    priority_queue<Node> pq;
    pq.push({A,0});

    while(!pq.empty())
    {
        Node now = pq.top();
        pq.pop();

        if(now.dist < dist[now.idx]) continue;

        Node* neighbor = head[now.idx];
        while(neighbor)
        {
            int total_dist = neighbor->dist + dist[now.idx];
            if(total_dist<dist[neighbor->idx])
            {
                dist[neighbor->idx] = total_dist;
                path[neighbor->idx] = now.idx;
                pq.push({neighbor->idx,total_dist});
            }
            neighbor = neighbor->next;
        }

    }

    // print_dist_path();

    vector<int> path_rev;
    path_rev.push_back(B);
    while(B!=A)
    {
        B = path[B];
        path_rev.push_back(B);
    }
    printf("%d\n",path_rev.size()-1);
    while(!path_rev.empty())
    {
        printf("%d ",path_rev.back());
        path_rev.pop_back();
    }

    return 0;
}
