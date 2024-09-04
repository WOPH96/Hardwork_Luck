// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int N;
vector<vector<int>> MAP;

// 입력변수생성

// dfs 구현

void print_map(vector<vector<int>> map)
{
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (auto &rows : map)
    {
        for (auto &elem : rows)
        {
            cout << elem << " ";
        }
        cout << "\n";
    }
    cout << " \n";
}
int getmax(vector<vector<int>> map)
{
    int MX = -9;
    for (auto &rows : map)
    {
        int temp = *max_element(rows.begin(), rows.end());
        if (temp > MX)
        {
            MX = temp;
        }
    }
    return MX;
}

int merged[20][20] = {0};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
// char direct[] = {'R', 'L', 'D', 'U'};
int mx = -1;

void move(int depth, vector<vector<int>> map)
{
    // 끝
    if (depth > 5)
    {
        return;
    }
    // 끝

    // 테스트용 map 출력
    print_map(map);

    // 이동 할때마다 최댓값 찾기
    int temp = getmax(map);
    if (temp > mx)
    {
        mx = temp;
    }

    // 이동

    for (int i = 0; i < 4; i++)
    {
        // 이동 방향 : dx[i],dy[i]
        // direct[] = {'R', 'L', 'D', 'U'};
        // 맵 복사가 있어야 할듯..
        vector<vector<int>> moved_map = map;
        if (i == 0)
        { // Rxs
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("brute_force-12100_input.txt", "r", stdin);
    cin >> N;
    // 현재 블록 값 입력
    for (int i = 0; i < N; i++)
    {
        vector<int> rows;
        for (int j = 0; j < N; j++)
        {
            int data;
            cin >> data;
            rows.push_back(data);
        }
        MAP.push_back(rows);
    }

    move(0, MAP);
    // cout << getmax(MAP);
    cout << mx << endl;

    // print_map(MAP);

    return 0;
}
