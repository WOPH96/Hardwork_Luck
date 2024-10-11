// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
struct Node
{
    int x, y;
    Node(int x, int y) : y(y), x(x) {}
};

// 입력, 테스트 출력

struct cmp
{
    bool operator()(Node &n1, Node &n2)
    {
        if (n1.y == n2.y)
        {
            return n1.x > n2.x;
        }

        return n1.y > n2.y;
    }
};
priority_queue<Node, vector<Node>, cmp> nodes;
void print();

void sol()
{
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes.emplace(x, y);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("sorting-11651_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();

    sol();
    print();

    return 0;
}

void print()
{
    while (!nodes.empty())
    {
        Node elem = nodes.top();
        cout << elem.x << " " << elem.y << "\n";
        nodes.pop();
    }
}
