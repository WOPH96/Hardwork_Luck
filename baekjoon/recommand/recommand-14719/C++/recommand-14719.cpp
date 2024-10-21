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
        bool find_one = false;
        int cnt = 0;
        for (int j = 0; j < w; j++)
        {
            // 아직 1을 못만났다면!
            // 이거 1이 홀수 일떄 수정해야함 ****
            if (arr[i][j] == 1 && !find_one)
            {
                find_one = true;
            }
            // 1을 만난 상태로 0을 만났다면!
            else if (arr[i][j] == 0 && find_one)
            {
                cnt++;
            }
            // 1을 만난 상태로 1을 또 만났다면!
            // 이거 1이 홀수 일떄 수정해야함 ****
            else if (arr[i][j] == 1 && find_one)
            {
                total_rain += cnt;
                cnt = 0;
                find_one = false;
            }
        }
        cout << h - i << "층 빗물 : " << total_rain << endl;
    }
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
    freopen("recommand-14719_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

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
