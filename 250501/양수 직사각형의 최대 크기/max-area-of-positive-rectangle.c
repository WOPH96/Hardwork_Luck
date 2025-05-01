#include <stdio.h>

int n, m;
int grid[20][20];

typedef struct
{
    int y,x;
}Pos;

typedef struct
{
    Pos st, end;
}Ractangle;

int max_size = -1;

void check(const Ractangle r)
{
    int size = 0;
    // printf("start[%d,%d] end[%d,%d]",r.st.y,r.st.x,)
    for(int i =r.st.y; i<=r.end.y; i++)
    {
        for(int j=r.st.x; j<=r.end.x;j++)
        {
            if(grid[i][j]<=0)
                return;
            else
                size++;
        }
    }
    if(max_size < size) max_size = size;
}

int main(void) {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &grid[i][j]);
    
    // Please write your code here.
    for(int s_y = 0; s_y<n; s_y++)
    {
        for(int s_x = 0; s_x<m;s_x++)
        {
            for(int e_y = s_y; e_y<n;e_y++)
            {
                for(int e_x = s_x; e_x<m; e_x++)
                {
                    Ractangle r = {{s_y,s_x},{e_y,e_x}};
                    check(r);
                }
            }
        }
    }
    printf("%d",max_size);
    return 0;
}