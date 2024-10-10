// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
struct Node
{
    int y, x;
    Node(int y, int x) : y(y), x(x) {}
};
vector<Node> nodes;
// 입력, 테스트 출력

struct cmp
{
    bool operator()(Node &n1, Node &n2)
    {
        if (n1.x == n2.x)
        {
            return n1.y < n2.y;
        }
        return n1.x < n2.x;
    }
};
void print();

void sol()
{
    sort(nodes.begin(), nodes.end(), cmp());
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int y, x;
        cin >> y >> x;
        nodes.emplace_back(y, x);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("sorting-11650_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();

    sol();
    print();

    return 0;
}

void print()
{
    for (auto &elem : nodes)
    {
        cout << elem.y << " " << elem.x << endl;
    }
}
