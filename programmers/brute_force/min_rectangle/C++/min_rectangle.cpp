#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 입력변수생성
vector<vector<int>> sizes;
// 입력변수생성
void print_arr()
{
    for (auto &rows : sizes)
    {
        for (auto &elem : rows)
        {
            cout << elem << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1];
}
int solution() // vector<vector<int>> sizes)
{

    // 명함 정보 정리: 가로가 더 큰 값으로 설정
    // print_arr();
    for (auto &size : sizes)
    {
        sort(size.begin(), size.end()); // 오름차순 정렬
    }

    // print_arr();

    // 가로 길이를 기준으로 내림차순 정렬
    sort(sizes.begin(), sizes.end(), compare);
    // print_arr();
    int max_width = sizes[0][1];  // 가장 긴 가로 길이
    int max_height = sizes[0][0]; // 첫 번째 명함의 세로 길이

    // 나머지 명함들의 세로 길이 중 최댓값 찾기
    for (int i = 1; i < sizes.size(); ++i)
    {
        max_height = max(max_height, sizes[i][0]);
    }

    return max_width * max_height;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("min_rectangle_input.txt", "r", stdin);

    int row = 5, col = 2;
    for (int i = 0; i < row; i++)
    {
        vector<int> rows;
        for (int j = 0; j < col; j++)
        {

            int data;
            cin >> data;
            rows.push_back(data);
        }
        sizes.push_back(rows);
    }

    cout << solution();

    return 0;
}
