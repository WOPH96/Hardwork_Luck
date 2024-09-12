// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 입력변수생성
int n, m;
vector<int> graph[1001];
bool visited[1001] = {0};
// 입력변수생성

// 입력, 테스트 출력
void input();
void print();

// 한번 연결된거 다 방문처리하고 true 반환
// 연결된건 바로 false 반환
bool dfs(int start)
{
    if (visited[start])
        return false;
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty())
    {
        int now = st.top();
        st.pop();
        for (auto &next : graph[now])
        {
            if (!visited[next])
            {
                st.push(next);
                visited[next] = true;
            }
        }
    }
    return true;
}

void sol()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dfs(i))
        {
            cnt++;
        }
    }
    cout << cnt;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-11724_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void print()
{
    for (int i = 0; i <= n; i++)
    {
        cout << i << "  ";
        for (auto &elem : graph[i])
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}
