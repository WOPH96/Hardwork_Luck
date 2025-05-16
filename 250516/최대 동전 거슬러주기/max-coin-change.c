#include <stdio.h>

#define MAX_M 10001
#define MAX_N 101

int coin[MAX_N];

#define max(a,b) ((a>b)?a:b)

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    
    // Please write your code here.
    
    int dp[MAX_M] = {0};

    for(int i = 1; i<=m; i++)
    {
        dp[i] = -1;
    }

    for(int i = 1; i<=m; i++)
    {
        for(int j = 0; j< n; j++)
        {
            if(dp[ i-coin[j] ] == -1) continue;
            if(i >= coin[j])
                dp[i] = max(dp[i],dp[i-coin[j]]+1); 
        }
    }

    // for(int i =0; i<=m ;i++)
    // {  
    //     printf("%d ",dp[i]);
    // }

    if(dp[m] == -1)
        printf("-1");
    else
        printf("%d",dp[m]);
    return 0;
}