#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int arr[3][3] = {
    {3, 5, 4},
    {1, 1, 2},
    {1, 3, 9}};

int y, x;
// 입력변수생성
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("19-1_input.txt", "r", stdin);

    cin >> y >> x;
    int size = sizeof(arr[0]) / sizeof(int);
    // cout << size;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 유효한 범위일 때
        if (0 <= nx && nx < size && 0 <= ny && ny < size)
        {
            // cout << ny << " " << nx << " " << arr[ny][nx] << "\n";
            sum += arr[ny][nx];
        }
    }
    cout << sum;
    return 0;
}
