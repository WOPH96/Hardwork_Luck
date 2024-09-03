#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int k, row, col;
vector<vector<int>> dungeons;
// 입력변수생성
int DS;
int visited[8] = {0}; // 최대 던전개수 8, 방문시 1
int mx = -1;
void dfs(int cnt, int fatique)
{
    /*끝나는조건*/
    // cnt -> 방문횟수!
    if (cnt > mx)
    {
        mx = cnt;
    }
    /*끝나는조건*/

    for (int i = 0; i < DS; i++)
    {
        // 방문했거나, 피로도 필요조건보다 딸리면
        if (visited[i] || fatique < dungeons[i][0])
            continue;

        // 조건 만족!
        // 피로도 소모, 방문 처리
        visited[i] = 1;
        // 조건 전달하여 수행
        dfs(cnt + 1, fatique - dungeons[i][1]);
        // dfs 전부 처리하고, 모든 방문횟수 초기화
        visited[i] = 0;
    }
}

int solution() // int k, vector<vector<int>> dungeons)
{
    int answer = -1;

    /*
    아이디어 :
    다 돌아보면 되잖아
    시작점 -> 다른곳 -> 탐방
    dfs

    */
    DS = dungeons.size();

    dfs(0, k);
    answer = mx;
    return answer;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("Fatigue_input.txt", "r", stdin);
    cin >> k >> row >> col;

    for (int i = 0; i < row; i++)
    {
        vector<int> rows;
        for (int j = 0; j < col; j++)
        {
            int data;
            cin >> data;
            rows.push_back(data);
        }
        dungeons.push_back(rows);
    }

    for (auto &rows : dungeons)
    {
        for (auto &elem : rows)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    cout << solution();

    return 0;
}
