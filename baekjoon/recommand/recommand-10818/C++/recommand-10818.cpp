// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n;
priority_queue<int> pq_max;
priority_queue<int, vector<int>, greater<int>> pq_min;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    cout << pq_min.top() << " " << pq_max.top() << endl;
}

void input()
{
    cin >> n;
    while (n)
    {
        int data;
        cin >> data;
        pq_max.push(data);
        pq_min.push(data);
        n--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("recommand-10818_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
