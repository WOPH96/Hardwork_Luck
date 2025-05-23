#include <stdio.h>
#define MAXN 1005
#define INF_N (~0x7fff0000)
#define max(a,b) ((a>b)?a:b)
int n;
int coin[MAXN];
int dp[MAXN][4];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &coin[i]);
    }
    // Please write your code here.

    for(int i =0 ;i<=n; i++)
    {
        for(int j =0;j<=3; j++)
        {
            dp[i][j] = INF_N ;
        }
    }
 
    dp[0][0] = 0;
    for(int i =1; i<=n; i++)
    {
        for(int j=0; j<=3; j++)
        {
            if(i>=2)
                dp[i][j] = max(dp[i][j],dp[i-2][j]+coin[i]);
            if(j>=1)
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+coin[i]);
        }
    }


    // for(int i = 0; i <=n; i++)
    // {
    //     for(int j =0; j<=3; j++)
    //     {
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }

    int max_val = -1;
    for(int j = 0; j<4; j++)
        max_val = max(max_val,dp[n][j]);

    printf("%d",max_val);
    return 0;
}