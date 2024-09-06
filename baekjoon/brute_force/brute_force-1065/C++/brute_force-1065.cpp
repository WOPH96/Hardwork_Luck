// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int N;
// 입력변수생성

int check(int num)
{
    if (num < 100)
        return 1;
    else
    {
        // cout << "num " << num << " ";
        int one = num % 10;
        num /= 10; // >> 1 하게 됨
        int ten = num % 10;
        int diff = ten - one; // 공차
        // cout << "diff " << diff << endl;
        while (num >= 10)
        {

            one = num % 10;
            num /= 10; // 다음자리수 가져오기
            ten = num % 10;
            // cout << ten << " " << one << endl;

            if ((ten - one) != diff)
                return 0;
        }
        // cout << "success" << endl;
        return 1;
    }
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("brute_force-1065_input.txt", "r", stdin);
    cin >> N;
    int cnt = 0;
    // cout << check(N);
    for (int i = 1; i <= N; i++)
    {
        cnt += check(i);
    }
    // check(123);
    cout << cnt;
    return 0;
}
