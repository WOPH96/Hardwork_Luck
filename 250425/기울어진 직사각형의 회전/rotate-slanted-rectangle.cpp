#include <iostream>
#include <cstdio>
using namespace std;

int n;
int grid[100][100];
int r, c, moving[4], dir;

void print(){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
void rotate()
{
    int temp = grid[r][c];
    int now_y = r, now_x = c;
    int ny = -1, nx = -1;
    int dy[] = {-1,-1,1,1};
    int dx[] = {1,-1,-1,1};
    auto is_valid = [&]{
        return (0<=ny&&ny<n&&
                0<=nx&&nx<n);
    };
    int cnt = 0;
    while(ny != r || nx !=c)
    {
        for(int i = 0 ; i<4; i++)
        {
            if(dir == 0)
            {
                for(int m = 0; m < moving[3-i]; m++)
                {
                    ny = now_y - dy[3-i];
                    nx = now_x - dx[3-i];
                    // printf("now[%d,%d], next[%d,%d]\n",now_y,now_x,ny,nx);
                    grid[now_y][now_x] = grid[ny][nx];
                    now_y = ny, now_x =nx;
                    // cnt++;
                }
            }
            else
            {
                for(int m = 0; m < moving[i]; m++)
                {
                    ny = now_y + dy[i];
                    nx = now_x + dx[i];
                    // printf("now[%d,%d], next[%d,%d]\n",now_y,now_x,ny,nx);
                    grid[now_y][now_x] = grid[ny][nx];
                    now_y = ny, now_x =nx;
                    // cnt++;
                }
            }
        }
        // if(cnt>10) break;
    }
    if(dir==0)
        grid[r-1][c+1] = temp;
    else
        grid[r-1][c-1] = temp;
    print();
    
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> moving[0] >> moving[1] >> moving[2] >> moving[3] >> dir;
    r--,c--;
    // Please write your code here.
    
    rotate();
    
    return 0;
}