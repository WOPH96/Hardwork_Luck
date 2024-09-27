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
    bool operator<(const Node &node) const
    {
        return this->w > node.w;
    }
};
// 입력변수생성
int v, e;
int start;
vector<int> graph; //[20001] = {0};
priority_queue<Node> pq[20001];
// bool visited[20001] = {false};
// const int INF = 9999999;
// 입력변수생성

// 입력, 테스트 출력
void input();
void print();
void print_result()
{
    for (int i = 1; i <= v; i++)
    {
        if (graph[i] == INF)
            cout << "INF" << endl;
        else
            cout << graph[i] << endl;
    }
}
void sol_dijkstra()
{
    priority_queue<Node> &sol_pq = pq[start];
    while (!sol_pq.empty())
    {
        // cout << sol_pq.top().dst << " " << sol_pq.top().w << endl;
        // sol_pq.pop();
        Node now = sol_pq.top();
        sol_pq.pop();
        if (graph[now.dst] < now.w)
            continue;

        graph[now.dst] = now.w;
        while (!pq[now.dst].empty())
        {
            Node next = pq[now.dst].top();
            sol_pq.push(Node(next.dst, next.w + now.w));
            pq[now.dst].pop();
        }
    }

    print_result();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-1753_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol_dijkstra();
    // delete graph;
    return 0;
}

void input()
{
    cin >> v >> e;
    cin >> start;
    // graph = new int[v + 1];
    graph.resize(v + 1, INF);
    // std::fill_n(graph, v + 1, INF);

    graph[start] = 0;

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

        if (graph[i] == INF)
            cout << setw(3) << "INF" << " ";
        else
            cout << setw(3) << graph[i] << " ";

        cout << endl;
    }

    // for (int i = 1; i <= v; i++)
    // {
    //     while (!pq[i].empty())
    //     {
    //         cout << "pq[" << i << "]  " << pq[i].top().dst << " " << pq[i].top().w << endl;
    //         pq[i].pop();
    //     }
    // }
    // cout << endl;
}
