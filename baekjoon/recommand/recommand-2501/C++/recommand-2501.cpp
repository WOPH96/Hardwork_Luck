// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, k;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    int cnt = 0;
    bool find_flag = false;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            cnt++;
            if (cnt == k)
            {
                cout << i << endl;
                find_flag = true;
                break;
            }
        }
    }
    if (!find_flag)
        cout << 0 << endl;
}

void input()
{
    cin >> n >> k;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("recommand-2501_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
