// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
// class counsel_info
// {
// public:
//     int t, p;
//     counsel_info(int _t, int _p)
//         : t(_t), p(_p)
//     {
//     }
// };
// 클래스로도 구현해보기

typedef struct
{
    int t;
    int p;
} counsel_info;

// 입력변수생성
int n;
int dp[16] = {0};
// 입력변수생성

void input_person(counsel_info *ci)
{
    if (ci == nullptr)
    {
        exit(1); // 프로그램 종료
    }
    for (int i = 0; i < n; i++)
    {
        cin >> (ci + i)->t;
        cin >> (ci + i)->p;
    }
    // ci[n].t = 0;
}

void print_person(counsel_info *ci)
{

    for (int i = 0; i < n; i++)
    {
        cout << (ci + i)->t << "," << (ci + i)->p << endl;
    }
}

void print_DP()
{

    for (int i = 0; i < 16; i++)
    {
        cout << "DP[" << i << "] :" << dp[i] << endl;
    }
}

int sol(counsel_info *ci)
{
    int max_pay = -1;
    for (int i = 0; i <= n; i++)
    {
        dp[i] = max(max_pay, dp[i]); // 현재 일수까지 최대 금액
        int next_idx = i + ci[i].t;
        if (next_idx <= n)
        {
            dp[next_idx] = max(dp[next_idx], dp[i] + ci[i].p);
        }
        max_pay = max(max_pay, dp[i]);
    }
    return max_pay;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("brute_force-14501_input.txt", "r", stdin);
    cin >> n;
    counsel_info *person = new counsel_info[n + 1];
    input_person(person);
    // print_person(person);

    cout << sol(person);
    // print_DP();

    // print_DP();

    delete[] person;
    return 0;
}
