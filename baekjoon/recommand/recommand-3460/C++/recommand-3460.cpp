// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int t;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol(int n)
{
    queue<int> q;
    while (n > 0)
    {
        // cout << n << endl;

        q.push(n % 2);
        n /= 2;
    }
    // cout << s.size() << endl;'
    int idx = 0;
    while (!q.empty())
    {
        if (q.front())
            cout << idx << " ";
        q.pop();
        idx++;
    }
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << s.top() << endl;
    //     // if (s.top())
    //     //     cout << i << " ";
    //     s.pop();
    // }
}

void input()
{
    cin >> t;
    while (t)
    {
        int num;
        cin >> num;
        sol(num);

        t--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("recommand-3460_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    print();

    return 0;
}

void print()
{
}
