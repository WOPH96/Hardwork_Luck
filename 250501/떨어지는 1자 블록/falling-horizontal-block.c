#include <stdio.h>
#define MAX_N 100

int n, m, k;
int grid[MAX_N][MAX_N];

int check(int row,int start_col)
{
    for(int j=start_col; j<start_col+m;j++)
    {
        if(grid[row][j] == 1)
            return 0;
    }
    return 1;
}

int main() {
    int i, j;
    scanf("%d %d %d", &n, &m, &k);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    k--;
    
    // Please write your code here.
    
    for(int i =n-1;i>=0;i--)
    {//아래서부터 
        if(check(i,k))
        { // 전부 0인공간 찾기 
            for(int j =k;j<k+m;j++)
            {
                grid[i][j] = 1;
            }
            break;
        }
    }

    for(int i = 0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}