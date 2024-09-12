// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, m;
int MAP[9][9] = {0};
// 입력변수생성

typedef struct
{
    int y;
    int x;
} Pos_t;

vector<Pos_t> virus;

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
    freopen("graph_search-14502_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2)
                virus.push_back({i, j});
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

    cout << "virus position" << endl;
    for (auto &elem : virus)
    {
        cout << "(" << elem.y << "," << elem.x << ")" << "  ";
    }
    cout << endl;
}
