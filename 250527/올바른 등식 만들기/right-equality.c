#include <stdio.h>

int n, m;   
int a[101];
long long dp[101][41];

#define max(a,b)((a>b)?a:b)

long long dfs(int idx,int sum)
{
    if( sum <-20 || sum >20 ) return 0;
    if(idx==n)
    {
        return (sum==m) ? 1 :0;
    }

    if(dp[idx][sum+20] != -1 )return dp[idx][sum+20];

    long long res  = 0;

    res += dfs(idx+1,sum+a[idx]);
    res += dfs(idx+1,sum-a[idx]);

    dp[idx][sum+20] = res;
    return res;
    
}
int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for(int j =0; j<41;j++)
        {
            dp[i][j]=0;
        }
    }
    // Please write your code here.

    // printf("%lld",dfs(0,0));

    dp[0][20] = 1;

    for (int i = 0 ; i <n; i++)
    {
        for(int sum = -20; sum<=20; sum++)
        {
            if(dp[i][sum+20] >0)
            {
                int next1 = sum + a[i];
                int next2 = sum - a[i];
                if(-20 <=next1 && next1 <=20)
                {
                    dp[i+1][next1+20] += dp[i][sum+20];
                }
                if(-20<=next2 && next2<=20)
                    dp[i+1][next2+20] += dp[i][sum+20];
            }

        }
    }
    printf("%lld",dp[n][m+20]);
    return 0;
}