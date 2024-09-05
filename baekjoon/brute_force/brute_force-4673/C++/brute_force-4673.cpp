// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성

// 입력변수생성
int dp[10001] = {0};
// void dfs(int num)
// {
//     if (dp[num])
//         return;
//     dp[num]=1;
//     num%
// }
void d(int num)
{
    // if (dp[num])
    //     return;
    int generated_num = 0;
    generated_num += num; // 본인
    while (num != 0)
    {
        generated_num += num % 10;
        num /= 10;
    }
    dp[generated_num] = 1;
    // d(generated_num);
}
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("brute_force-4673_input.txt", "r", stdin);

    for (int i = 1; i <= 10000; i++)
    {
        d(i);
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (!dp[i])
            cout << i << endl;
    }
    return 0;
}
 
