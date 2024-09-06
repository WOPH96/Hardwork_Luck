// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, m;
vector<int> cards;
// 입력변수생성
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("brute_force-2798_input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int card;
        cin >> card;
        cards.push_back(card);
    }

    // for (auto &elem : cards)
    // {
    //     cout << elem << " ";
    // }
    int mn = 300000;
    int sum, diff, flag;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                sum = cards[i] + cards[j] + cards[k];
                // printf("%d+%d+%d=%d\n", cards[i], cards[j], cards[k], sum);
                diff = abs(m - sum);
                if (diff < mn && sum <= m)
                {
                    // printf("(%d,%d,%d)", diff, sum, mn);
                    mn = diff;
                    flag = sum;
                }
            }
        }
    }
    cout << flag << endl;
    return 0;
}
