#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m, d;
int SOB[1000][1000] = {0};
int works[5000] = {0};
// 입력변수생성

// void grow_up()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             SOB[i][j]++;
//         }
//     }
// }

int do_work(int day, priority_queue<int> &pq)
{
    int have_to_work = works[day];

    // 다같이 증가하니, 날짜에 맞추어 + 하면 될듯 !
    int day_income = 0;
    for (int i = 0; i < have_to_work; i++)
    {
        // if (pq.top().second == day)
        // {
        //     break;
        // }
        day_income += (pq.top() + day - 1);
        pq.pop();
        pq.push(-1 * day + 1);
    }

    return day_income;
}
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("bamboo_input.txt", "r", stdin);

    cin >> n >> m >> d;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> SOB[i][j];
            pq.push(SOB[i][j]);
        }
    }
    for (int i = 0; i < d; i++)
    {
        cin >> works[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << SOB[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < d; i++)
    // {
    //     cout << works[i] << " ";
    // }
    // cout << endl;
    long long sum = 0;

    for (int i = 0; i < d; i++)
    {
        sum += do_work(i, pq);
    }

    cout << sum;
    return 0;
}
