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

counsel_info *person;

// 입력변수생성
int n;
int max_pay = 0;
int dp[16] = {0};
// 입력변수생성

void input_person();
void print_person();
void print_DP();

void recur(int idx, int sum)
{
    if (idx > n)
        return;
    max_pay = max(max_pay, sum);
    for (int i = idx; i < n; i++)
    {
        recur(person[i].t + i, sum + person[i].p);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("brute_force-14501_input.txt", "r", stdin);
    cin >> n;
    person = new counsel_info[n + 1];
    input_person();
    // print_person();
    // print_DP();
    recur(0, 0);
    // print_DP();
    cout << max_pay;

    delete[] person;
    return 0;
}
void input_person()
{
    if (person == nullptr)
    {
        exit(1); // 프로그램 종료
    }
    for (int i = 0; i < n; i++)
    {
        cin >> (person + i)->t;
        cin >> (person + i)->p;
    }
    person[n].t = 1;
}

void print_person()
{

    for (int i = 0; i < n; i++)
    {
        cout << (person + i)->t << "," << (person + i)->p << endl;
    }
}

void print_DP()
{

    for (int i = 0; i < 16; i++)
    {
        cout << "DP[" << i << "] :" << dp[i] << endl;
    }
}
