#include <stdio.h>

int n;
int red[205];
int blue[205];
int dp[205][101];
#define max(a,b) ((a>b)?a:b)

int total;

int dfs(int idx,int red_used)
{
    int blue_used = idx-red_used;
    if(idx == total)
    {
        if(red_used == n && blue_used == n)
            return 0;
        else
            return 0x80000000;

    }
    if(dp[idx][red_used] != -1) return dp[idx][red_used];

    int res = 0;

    if(red_used<n) res = max(res,dfs(idx+1,red_used+1)+red[idx]);
    if(blue_used<n) res = max(res,dfs(idx+1,red_used)+blue[idx]);

    dp[idx][red_used] = res;
    return dp[idx][red_used]; 
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d %d", &red[i], &blue[i]);
    }

    // Please write your code here.
    
    total = 2*n;

    for(int i = 0; i<=total;i++)
    {
        for(int j =0; j<=n;j++)
        {
            dp[i][j] = -1;
        }
    }

    // dp[i][r] -> i번째 줄 카드까지 왔을 때, red를 몇번 선택했는가
    // dp[0][0] = 0;
    // for(int i =0; i<total; i++)
    // {
    //     for(int r =0; r<=n; r++)
    //     {
    //         if(dp[i][r] == -1) continue;
            
    //         if(r<n)
    //             dp[i+1][r+1] = max(dp[i+1][r+1],dp[i][r]+red[i]);
    //         if(i-r <n)
    //             dp[i+1][r] = max(dp[i+1][r],dp[i][r]+blue[i]);
            
    //     }
    // }
    // printf("%d",dp[total][n]);
    printf("%d",dfs(0,0));
    // for(int i = 0; i<=total; i++)
    // {
    //     for(int r = 0; r<=n; r++)
    //     {
    //         printf("%d ",dp[i][r]);
    //     }
    //     printf("\n");
    // }
    return 0;
}