#include <stdio.h>
int a[100005];
int dp[100005][12];

#define INF_N 0x80000000
#define max(a,b) ((a>b)?a:b)

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Please write your code here.
    //init
    {
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                dp[i][j] = INF_N;
            }
        }
    }


    int max_val = -1;
    for(int i = 0 ; i <n; i++)
    {
        // printf("%d\n",dp[i][k] );
        if(a[i]<0) dp[i][1] = a[i];
        else        dp[i][0] = a[i];
        for(int j =0; j<=k; j++)
        {
            if(i>=1 && dp[i-1][j] == INF_N) continue;
            if(a[i]<0)
                dp[i][j+1] = max(dp[i-1][j]+a[i],a[i]);
            else
                dp[i][j] = max(dp[i-1][j]+a[i],a[i]);

            max_val = max(max_val,dp[i][j]);
        }
        
    }

    // for(int i = 0; i<n; i++)
    // {
    //     for(int j =0 ;j <=k; j++)
    //     {
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d",max_val);
    return 0;
}