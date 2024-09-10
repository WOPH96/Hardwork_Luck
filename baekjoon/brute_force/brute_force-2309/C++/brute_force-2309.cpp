// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int arr[9];
// 입력변수생성

int check_sum(int avoid_1, int avoid_2)
{
    int sum = 0;

    for (int i = 0; i < 9; i++)
    {
        if (i != avoid_1 && i != avoid_2)
        {
            sum += arr[i];
            // cout << i << " " << sum << endl;
        }
    }

    return sum;
}
void get_answer(int avoid_1, int avoid_2, int *smalls)
{
    int idx = 0;
    for (int i = 0; i < 9; i++)
    {
        if (i != avoid_1 && i != avoid_2)
        {
            *(smalls + idx) = arr[i];
            idx++;
        }
    }

    sort(&smalls[0], &smalls[7]);

    for (int i = 0; i < 7; i++)
    {
        cout << smalls[i] << endl;
    }
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("brute_force-2309_input.txt", "r", stdin);

    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }
    // 9개중 2개를 골라서 뺴고 다 더하는 것과 동일함
    int smalls[7];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == j)
                continue;

            if (check_sum(i, j) == 100)
            {

                get_answer(i, j, smalls);
                return 0;
            }
        }
    }

    return 0;
}
