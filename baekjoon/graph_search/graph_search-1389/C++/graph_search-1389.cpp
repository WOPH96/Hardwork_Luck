// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m;
// 다른 변수 생성
vector<int> graph[101];
int bacon_dist[101][101] = {0};
// 입력, 테스트 출력

struct Node
{
    int person, dist;
    Node(int p, int d) : person(p), dist(d) {}
};

struct cmp
{

    bool operator()(Node &n1, Node &n2)
    {

        if (n1.dist == n2.dist)
        {
            return n1.person > n2.person;
        }
        return n1.dist > n2.dist;
    }
};

void print();

void bfs(int start)
{
    int visited[101] = {0};
    queue<Node> q;
    q.emplace(start, 0);
    visited[start] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        for (int &next : graph[now.person])
        {
            if (visited[next])
                continue;
            visited[next] = true;
            bacon_dist[start][next] = now.dist + 1;
            q.emplace(next, now.dist + 1);
        }
    }
}

void sol()
{
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }

    int min_dist = 99999;
    int min_person = 102;
    priority_queue<Node, vector<Node>, cmp> pq;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            sum += bacon_dist[i][j];
        }
        pq.emplace(i, sum);
    }
    cout << pq.top().person << endl;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("graph_search-1389_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto &relation : graph[i])
        {
            cout << relation << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << bacon_dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
