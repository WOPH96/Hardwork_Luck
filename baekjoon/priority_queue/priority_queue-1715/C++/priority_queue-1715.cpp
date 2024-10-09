// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
priority_queue<int, vector<int>, greater<int>> pq;
// 입력, 테스트 출력

void print();

void sol()
{
    long long min_data = 0;
    while (1)
    {
        int d1, d2, tot;
        if (pq.size() >= 2)
        {
            d1 = pq.top();
            pq.pop();
            d2 = pq.top();
            pq.pop();
            tot = d1 + d2;
            min_data += tot;
        }
        else if (pq.size() == 1)
        {

            pq.pop();
        }
        if (pq.empty())
            break;
        pq.push(tot);
    }
    cout << min_data << "\n";
}

void input()
{
    cin >> n;
    while (n)
    {
        int data;
        cin >> data;
        pq.push(data);
        n--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("priority_queue-1715_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void print()
{
    while (!pq.empty())
    {

        cout << pq.top() << " ";
        pq.pop();
    }
}
