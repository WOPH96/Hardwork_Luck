#include <iostream>

using namespace std;

int n, m, q;
int grid[100][100];

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

void print()
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<< grid[i][j] << " ";
        } 
        cout << "\n";
    }
}
void conv(int r1,int c1, int r2, int c2)
{
    int temp[100][100] = {0};
    int dy[] = {0,0,0,-1,1};
    int dx[] = {0,1,-1,0,0};
    for(int i = r1; i<=r2; i++)
    {
        for(int j=c1; j<=c2;j++)
        {
            int sum = 0;
            int cnt = 0;
            for(int dir = 0 ;dir <5; dir ++)
            {
                int ny = i + dy[dir], nx = j + dx[dir];
                if((0<=ny && ny<n &&
                    0<=nx && nx<m))
                {
                    sum+=grid[ny][nx];
                    cnt++;
                }
            }
            temp[i][j] = (int)sum/cnt;
        }
        // cout << "\n";
    }
    for(int i = r1; i<=r2; i++)
    {
        for(int j=c1; j<=c2;j++)
        {
            grid[i][j] = temp[i][j];
        }
        // cout << "\n";
    }


}
void move(int r1,int c1, int r2, int c2)
{
    int temp = grid[r1][c1];
    int now_dir = 0;
    int ny = -1, nx = -1;
    int cury = r1, curx = c1;
    int cnt = 0;
    while(ny != r1 || nx != c1)
    {
        ny = cury + dy[now_dir];
        nx = curx + dx[now_dir];
        if(r1<=ny && ny <=r2 && c1 <= nx && nx <=c2)
        {
            grid[cury][curx] = grid[ny][nx];
            cury = ny, curx = nx;
            // cnt++;
        }
        else
        {
            now_dir++;
        }
        
        // if(cnt>10)break;
    }
    grid[r1][c1+1] = temp;
    

}
int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> grid[i][j];

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--,c1--,r2--,c2--;
        /*가장 왼쪽 상단 값이 
        아랫값, 아랫값 없으면
        오른쪽값, 오없
        위값, 위없
        왼값
        */
        move(r1,c1,r2,c2);
        conv(r1,c1,r2,c2);
    }
    print();
    // Please write your code here.
    
    return 0;
}
