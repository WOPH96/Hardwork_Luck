// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int from;
    int to;
    Node(int f, int t) : from(f), to(t) {}
    friend ostream &operator<<(ostream &out, Node &n)
    {
        out << n.from << "," << n.to;
        return out;
    }
};

// 입력변수생성
int n, m;
vector<Node> nodes;
int arr[101] = {0};
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

void sol()
{
    for (int i = 0; i < m; i++)
    {
        int temp;
        temp = arr[nodes[i].from];
        arr[nodes[i].from] = arr[nodes[i].to];
        arr[nodes[i].to] = temp;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("simulation-10813_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    print();

    return 0;
}

void input()
{
    cin >> n >> m;
    // nodes.resize(n + 1, {0, 0});
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        nodes.push_back({from, to});
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
}
void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     cout << nodes[i] << " ";
    // }
    // cout << endl;
}
