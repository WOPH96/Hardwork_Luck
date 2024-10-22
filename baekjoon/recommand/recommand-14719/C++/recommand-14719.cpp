// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int h, w;
int arr[501][501] = {0};
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{

    // 맨아랫줄부터 시작
    int total_rain = 0;
    for (int i = h - 1; i >= 0; i--)
    {

        int prev = -1;
        int cnt = 0;
        for (int j = 0; j < w; j++)
        {
            // 1을 만나고 처음
            if (arr[i][j] == 1 && prev == -1)
            {

                prev = 1;
            }
            // 1을 만난적이 있고, 현재가 0인 경우
            else if (arr[i][j] == 0 && prev != -1)
            {
                cnt++;
                prev = 0;
            }
            // 이전이 0이고 현재가 1인경우
            else if (arr[i][j] == 1 && prev == 0)
            {
                total_rain += cnt;
                cnt = 0;
                prev = 1;
            }
        }
        // cout << h - i << "층 빗물 : " << total_rain << endl;
    }
    cout << total_rain << endl;
}

void input()
{
    cin >> h >> w;
    for (int i = 0; i < w; i++)
    {
        int rain;
        cin >> rain;
        for (int j = h - rain; j < h; j++)
        {
            arr[j][i] = 1;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("recommand-14719_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
