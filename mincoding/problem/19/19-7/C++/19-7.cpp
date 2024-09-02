#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
typedef struct
{
    int y;
    int x;
} coordinate;

coordinate pos[4];
int vect[4][3] = {0};
// 입력변수생성
void mapping();
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("19-7_input.txt", "r", stdin);
    for (int i = 0; i < 4; i++)
    {
        cin >> pos[i].y >> pos[i].x;
    }

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << positions[i][j];
    //     }
    // }
    mapping();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

void mapping()
{

    for (int i = 0; i < 4; i++)
    {
        int y = pos[i].y;
        int x = pos[i].x;
        // cout << y << " " << x << endl;
        vect[y][x] = 5;
    }
}