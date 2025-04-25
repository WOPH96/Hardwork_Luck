#include <iostream>

using namespace std;

int n, m, q;
int grid[100][100];

typedef enum
{
    LEFT,
    RIGHT
}LR;

typedef enum
{
    UP,
    DOWN
}Updown;


void wind(int r,int d)
{

    if(d==LEFT)
    {
        int temp = grid[r][m-1];
        for(int j = m-1; j>0; j--)
        {
            grid[r][j] = grid[r][j-1];
        }
        grid[r][0] = temp;
    }
    else
    {
        int temp = grid[r][0];
        for(int j = 0; j<m-1; j++)
        {
            grid[r][j] = grid[r][j+1];
        }
        grid[r][m-1] = temp;
    }
}

void print(int graph[][100])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

bool is_valid(int r)
{
    return (0<=r && r<n);
}

void check(int r, Updown ud, int dir)
{
    dir^=1;
    if(ud == UP)
    {
        if(!is_valid(r-1)) return;
        bool influence = false;
        for(int j = 0 ; j <m; j++)
        {
            if (grid[r-1][j] == grid[r][j])
            {
                influence = true;
                break;
            }  
        }
        if(influence)
        {
            wind(r-1,dir);
            check(r-1,ud,dir);
        }
    }
    else
    {
        if(!is_valid(r+1)) return;
        bool influence = false;
        for(int j = 0 ; j <m; j++)
        {
            if (grid[r+1][j] == grid[r][j])
            {
                influence = true;
                break;
            }  
        }
        if(influence)
        {
            wind(r+1,dir);
            check(r+1,ud,dir);
        }
    }

}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        
        cin >> r >> d;
        r--;
        int dir = ((d=='L') ? LEFT : RIGHT);
        // 바람 이동
        wind(r,dir);
        // 주변 영향 확인
        //sub problem으로 나눠야함...
        check(r,UP,dir);
        check(r,DOWN,dir);
        

    }
    print(grid);
    // Please write your code here.

    return 0;
}
