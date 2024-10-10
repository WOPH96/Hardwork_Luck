// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력변수생성
int n, k;

// 다른 변수 생성
struct Jew
{
    int m, v;
    Jew(int m, int v) : m(m), v(v) {}
    friend ostream &operator<<(ostream &out, Jew &j)
    {
        out << j.m << "," << j.v;
        return out;
    }
};

struct cmp
{
    bool operator()(Jew &j1, Jew &j2)
    {
        if (j1.v == j2.v)
        {
            return j1.m > j2.m;
        }
        return j1.v < j2.v;
    }
};

priority_queue<Jew, vector<Jew>, cmp> jew_pq;
priority_queue<int, vector<int>, less<int>> bag_pq;
// 입력, 테스트 출력

void print();

void sol()
{
    long long tot = 0;
    while (!jew_pq.empty())
    {
        if (jew_pq.top().m <= bag_pq.top())
        {
            tot += jew_pq.top().v;
            bag_pq.pop();
        }
        jew_pq.pop();
        if (bag_pq.empty())
            break;
    }
    cout << tot << "\n";
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        jew_pq.emplace(m, v);
    }
    for (int i = 0; i < k; i++)
    {
        int weight;
        cin >> weight;
        bag_pq.push(weight);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("priority_queue-1202_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void print()
{
    while (!jew_pq.empty())
    {
        Jew J = jew_pq.top();
        cout << J << "\n";
        jew_pq.pop();
    }
    while (!bag_pq.empty())
    {
        cout << bag_pq.top() << "\n";
        bag_pq.pop();
    }
}
