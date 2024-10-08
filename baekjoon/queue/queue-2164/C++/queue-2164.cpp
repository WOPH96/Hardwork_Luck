// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
queue<int> q;
// 입력, 테스트 출력

void print();

void sol()
{
    while (1)
    {
        int top;
        if (q.size() == 1)
            break;
        q.pop();
        if (q.size() == 1)
            break;
        top = q.front();
        q.pop();
        q.push(top);
    }
    cout << q.front() << endl;
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("queue-2164_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void print()
{
}
