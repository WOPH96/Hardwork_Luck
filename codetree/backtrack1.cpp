#include <iostream>
#include <vector>

using namespace std;

typedef enum
{
    EMPTY,
    WALL
} Map_info;

typedef struct
{
    int y, x;
} Pos;

int result = 0;
int dy[] = {1, 0};
int dx[] = {0, 1};

void dfs(Pos now, vector<vector<int>> &A, int dir, int K)
{
    if (now.y == n - 1 && now.x == n - 1)
    {
        result++;
        return;
    }

    visited[now.y][now.x] = true;
    ny =
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            // if(A[i][j] == WALL)
            //     mem[i][j] = -1;
        }
    }

    dfs({0, 0}, A, 0, K);
    dfs({0, 0}, A, 1, K);

    cout << result;
    // Please write your code here.
}
