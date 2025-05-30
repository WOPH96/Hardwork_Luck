#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100001
#define INF 0x7fff0000

int n, m;


struct Node
{
    int idx;
    int dist;
    Node* next;

    friend bool operator <(const Node n1, const Node n2)
    {
        return n1.idx < n2.idx;
    }
};

Node* head[MAX_N];
int dist[MAX_N];

void make_graph(int from,int to, int weight)
{
    //반대로 연결하기
    Node* data = new Node();
    data->idx = from; //연결 대상, 원래는 to 
    data->dist = weight;
    data->next = head[to];
    head[to] = data;
}

void print_graph()
{
    for(int i =1; i<=n; i++)
    {
        Node *temp = head[i];
        printf("Node %d : ",i);
        while(temp)
        {
            printf("[%d,%d] ",temp->idx, temp->dist);
            temp = temp->next;
        }
        cout << "\n";
    }
}

int main() {
    cin >> n >> m;
    for (int k = 0; k < m; k++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        make_graph(from,to,weight);
    }

    // Please write your code here.

    // print_graph();

    for(int i = 1; i<n; i++)
    {
        dist[i] = INF;
    }

    dist[n] = 0; //원래 0이긴 함

    priority_queue<Node> pq;
    pq.push({n,0});

    while(!pq.empty())
    {
        Node now = pq.top();
        pq.pop();

        Node* cur = head[now.idx];
        if(now.dist < dist[now.idx]) continue;

        while(cur)
        {
            int total_dist = cur->dist + dist[now.idx];

            if(total_dist < dist[cur->idx])
            {
                dist[cur->idx] = total_dist;
                pq.push({cur->idx,total_dist});
            }

            cur = cur->next; 
        }
    }
    
    int lateset_dist = *max_element(&dist[0],&dist[n]);
    printf("%d",lateset_dist);
    
    return 0;
}
