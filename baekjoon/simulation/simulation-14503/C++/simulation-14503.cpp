// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, m;
int r, c, d;
int MAP[51][51] = {0};
// 다른 변수 생성
//          북  동 남  서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

enum ROOM
{
    EMPTY,
    WALL
};

// 입력, 테스트 출력
void input();
void print();

// void sol(){
// }

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("simulation-14503_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input()
{
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
void print()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
