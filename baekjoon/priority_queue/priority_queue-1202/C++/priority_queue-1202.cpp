// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 입력변수생성
int n, k;

// 다른 변수 생성
struct Jew
{
    int mass, value;
    Jew(int m, int v) : mass(m), value(v) {}
    friend ostream &operator<<(ostream &out, Jew &j)
    {
        out << j.mass << "," << j.value;
        return out;
    }
};

struct cmp
{
    bool operator()(Jew &j1, Jew &j2)
    {
        if (j1.mass == j2.mass)
        {
            return j1.value > j2.value;
        }
        return j1.mass < j2.mass;
    }
};

vector<Jew> jewels;
vector<int> bags;
priority_queue<int> pq;
// 입력, 테스트 출력

void print();

void sol()
{
    sort(jewels.begin(), jewels.end(), cmp());
    sort(bags.begin(), bags.end(), less<int>());
    int idx = 0;
    long long max_value = 0;
    for (auto &bag : bags)
    {
        while (idx < n && jewels[idx].mass <= bag)
        {
            pq.push(jewels[idx].value);
            idx++;
        }
        if (!pq.empty())
        {
            int best_value_jew = pq.top();
            max_value += best_value_jew;
            pq.pop();
        }
    }
    cout << max_value << endl;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        jewels.emplace_back(m, v);
    }
    for (int i = 0; i < k; i++)
    {
        int weight;
        cin >> weight;
        bags.push_back(weight);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("priority_queue-1202_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    print();

    return 0;
}

void print()
{
    for (auto &jw : jewels)
    {
        cout << jw << endl;
    }
    for (auto &bag : bags)
    {
        cout << bag << endl;
    }
}
