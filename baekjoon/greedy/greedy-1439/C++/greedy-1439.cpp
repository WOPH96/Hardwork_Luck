// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
string str;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    char prev = str[0];
    int zero_cnt = 0;
    int one_cnt = 0;

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != prev)
        {
            // cout << "Hello" << endl;
            if (prev == '0')
                zero_cnt++;
            else if (prev == '1')
                one_cnt++;
            prev = str[i];
        }
    }

    cout << max(zero_cnt, one_cnt) << endl;
}

void input()
{
    cin >> str;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("greedy-1439_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
