// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
vector<int> datas;
priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int, vector<int>, less<int>> max_pq;
// 입력, 테스트 출력

void print();

void sol()
{
    for (auto &data : datas)
    {
        if (min_pq.size() == max_pq.size())
        {
            max_pq.push(data);
        }
        else
        {
            min_pq.push(data);
        }
        if (!min_pq.empty() &&
            min_pq.top() < max_pq.top())
        {
            int max_top = max_pq.top();
            int min_top = min_pq.top();
            max_pq.pop();
            min_pq.pop();
            max_pq.push(min_top);
            min_pq.push(max_top);
        }
        cout << max_pq.top() << "\n";
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        datas.push_back(data);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("priority_queue-1655_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void print()
{
}
