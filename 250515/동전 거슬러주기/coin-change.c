#include <stdio.h>
#include <string.h>
int n, m;
int coin[101];

#define min(a,b) ((a<b)?a:b)
#define MAX_VAL 0x7fff0000
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    
    // Please write your code here.
    // 큰동전부터 ㄱㄱ씽

    int dp[10001] = {0};

    for(int i = 0 ; i <= m; i++)
    {
        dp[i] = MAX_VAL;
    }
    dp[0] = 0;
    for(int i = 1; i<=m; i++)
    {
        for(int j=0; j<n; j++)
        {
            
            if(i>=coin[j])
            {
                if(dp[i-coin[j]] == MAX_VAL)
                {
                    continue;
                }
                dp[i] = min(dp[i],dp[i-coin[j]]+1);
            }
        }
    }
    if(dp[m] == MAX_VAL) printf("-1");
    else printf("%d",dp[m]);
    // for(int i =0; i<=m; i++)
    // {
    //     printf("%d ",dp[i]);
    // }
    return 0;
}