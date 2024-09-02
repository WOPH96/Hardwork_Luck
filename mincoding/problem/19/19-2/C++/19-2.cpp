#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int MAP[5][5] = {
    {3, 3, 5, 3, 1},
    {2, 2, 4, 2, 6},
    {4, 9, 2, 3, 4},
    {1, 1, 1, 1, 1},
    {3, 3, 5, 9, 2}};
// 입력변수생성

int sum(int y, int x);
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("19-2_input.txt", "r", stdin);
    int cor_y, cor_x;
    int max = 0;
    int res;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((res = sum(i, j)) > max)
            {
                max = res;
                cor_y = i;
                cor_x = j;
            }
        }
    }
    cout << cor_y << " " << cor_x;
    return 0;
}

int sum(int y, int x)
{
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, 1, -1};
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5)
        {
            sum += MAP[ny][nx];
        }
    }
    return sum;
}