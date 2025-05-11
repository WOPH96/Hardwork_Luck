#include <iostream>
#include <vector>

using namespace std;

int N, K;                 // 격자의 크기와 최대 방향 전환 횟수
vector<vector<int>> grid; // 격자판
int result = 0;

// 방향 배열 (우측, 아래)
int dx[2] = {0, 1};
int dy[2] = {1, 0};

bool is_valid(int y, int x)
{
    return (0 <= y && y < N &&
            0 <= x && x < N &&
            grid[y][x] == 0);
}

// DFS 함수
void dfs(int x, int y, int dir, int turns)
{
    // (N, N)에 도달했을 경우
    if (x == N - 1 && y == N - 1)
    {
        if (turns <= K)
        {
            result++;
        }
        return;
    }

    // 다음 위치로 이동
    for (int nextDir = 0; nextDir < 2; ++nextDir)
    {
        int nx = x + dx[nextDir];
        int ny = y + dy[nextDir];

        // 새로운 방향은 direction이 바뀌었는지 확인
        int newTurns = (dir != -1 && dir != nextDir) ? turns + 1 : turns;

        // 유효한 위치이고, grid[nx][ny]가 0이며 방향 전환 횟수가 K를 넘지 않는 경우
        if (is_valid(ny, nx) && newTurns <= K)
        {
            dfs(nx, ny, nextDir, newTurns);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("backtracking-1_input.txt", "r", stdin);
    // 제출 시 주석처리
    cin >> N >> K;
    grid = vector<vector<int>>(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> grid[i][j];
        }
    }

    // DFS 시작: 초기 위치 (0, 0)에서 시작
    dfs(0, 0, -1, 0);

    // 결과 출력
    cout << result << endl;

    return 0;
}
