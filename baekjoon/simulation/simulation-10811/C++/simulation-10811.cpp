// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int n, m;
vector<pair<int, int>> order;
// 다른 변수 생성
int arr[101] = {0};
// 입력, 테스트 출력
void input();
void print();
void sort_rev(int *start, int n)
{
    for (int i = 0; i < n; i++)
    {
        start[n]
    }
}
void sol()
{

    for (int i = 0; i < m; i++)
    {
        int start = order[i].first;
        int end = order[i].second;
        sort_rev(&arr[start], end - start);
        print();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("simulation-10811_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();
    // print();

    return 0;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        order.push_back({start, end});
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
}
void print()
{
    // for (int i = 0; i < m; i++)
    // {
    //     cout << order[i].first << "," << order[i].second << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
