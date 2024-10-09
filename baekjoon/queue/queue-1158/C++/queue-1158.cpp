// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, k;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    cout << "<";
    while (!q.empty())
    {

        for (int cnt = 0; cnt < k - 1; cnt++)
        {
            q.push(q.front());
            q.pop();
        }
        int target_num = q.front();
        q.pop();
        if (q.size() == 0)
            cout << target_num;
        else
            cout << target_num << ", ";
    }
    cout << ">" << endl;
}

void input()
{
    cin >> n >> k;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("queue-1158_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void print()
{
}
