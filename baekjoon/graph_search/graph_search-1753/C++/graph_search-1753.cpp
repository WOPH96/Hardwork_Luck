// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip> // 입출력 조정자
#include <queue>
#define INF (9999999)

using namespace std;

struct Node
{
    int dst;
    int w;
    Node(int d, int w) : dst(d), w(w) {}
    bool operator<(const Node &node) const{
        return this->w > node.w;
    }
};
// 입력변수생성
int v, e;
int start;
int graph[20001][20001] = {0};
priority_queue<Node> pq[20001];
bool visited[20001] = {false};
// const int INF = 9999999;
// 입력변수생성

// 입력, 테스트 출력
void input();
void print();

void sol_bfs()
{
    priority_queue<int> pq;
    pq.push(start);
    // visited[start] = true;
    
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-1753_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol_bfs();
    

    return 0;
}

void input()
{
    cin >> v >> e;
    cin >> start;
    // fill_n(&graph[1][1], (v * v), INF);
    for (int i = 1; i <= v; i++)
    {
        fill_n(graph[i], v + 1, INF);
    }

    for (int i = 0; i < e; i++)
    {
        int src, dst, weight;
        cin >> src >> dst >> weight;
        pq[src].push(Node(dst, weight));
        // graph[src][dst] = weight;
    }
    
}
void print()
{
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (graph[i][j] == INF)
                cout << setw(3) << "INF" << " ";
            else
                cout << setw(3) << graph[i][j] << " ";
        }
        cout << endl;
    }

    // for(int i=1;i<=v;i++){
    //     while(!pq[i].empty()){
    //         cout << "pq["<<i<<"]  " << pq[i].top().dst << " " << pq[i].top().w <<endl;
    //         pq[i].pop();
            
    //     }
    // }
    // cout << endl;
}
