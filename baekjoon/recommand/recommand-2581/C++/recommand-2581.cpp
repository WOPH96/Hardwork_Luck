// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int first, last;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

bool is_primary(int num)
{
    int cnt = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            cnt++;
        if (cnt > 2)
            break;
    }
    if (cnt == 2)
        return true;
    else
        return false;
}

void sol()
{
    int cnt = 0;
    int sum = 0;
    int mn = -1;
    for (int i = first; i <= last; i++)
    {
        if (is_primary(i))
        {
            sum += i;
            cnt++;
            // cout << i << " " << endl;
            if (cnt == 1)
            {
                mn = i;
            }
        }
    }
    if (mn == -1)
    {
        cout << mn << endl;
    }
    else
        cout << sum << "\n"
             << mn << endl;
}

void input()
{
    cin >> first >> last;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("recommand-2581_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
