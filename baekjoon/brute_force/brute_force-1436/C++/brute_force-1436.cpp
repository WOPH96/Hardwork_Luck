// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int N;
// 입력변수생성
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("brute_force-1436_input.txt", "r", stdin);
    cin >> N;
    int cnt = 0;
    for (long i = 666; i < 100000000; i++)
    {
        if (to_string(i).find("666") != string::npos)
            cnt++;
        if (cnt == N)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
