// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, s;
// 다른 변수 생성
int arr[21] = {0};
// 입력, 테스트 출력

void print();

int cnt = 0;

void dfs(int data, int sum)
{
}

void sol()
{
    for (int i = 0; i < n; i++)
    {
        dfs(arr[i], 0);
    }
}

void input()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("back_tracking-1182_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
    for (auto &elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
}
