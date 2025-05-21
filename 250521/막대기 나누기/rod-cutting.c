#include <stdio.h>

int n;
int profit[101];

#define max(a,b) ((a>b)?a:b)

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &profit[i]);
    }

    
    // Please write your code here.
    // 남은 길이로 만들 수 있는 최대 금액을 dp로 저장
    // dp[1] -> 1만 남았을 때 얻을 수 있는 최대 금액
    // dp[n] -> n만 남았을 때 얻을 수 있는 최대 금액
    
    // dp[2] -> dp[1] + dp[1] vs dp[2]
    // dp[3] -> dp[1]*3 dp[1] + dp[2] vs dp[3]
    // i = 2 , j = 1;
    int dp[101]= {0};
    for (int i =1; i<=n; i++)
    {
        dp[i] = profit[i];
        for(int j=1; j<i; j++)
        {
            dp[i] = max(dp[i],dp[i-j]+profit[j]);
        }
    }

    printf("%d",dp[n]);
    
    return 0;
}