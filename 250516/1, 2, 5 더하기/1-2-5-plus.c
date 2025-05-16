#include <stdio.h>

#define MOD 10007
int main() {
    int n;
    scanf("%d", &n);
    
    // Please write your code here.
    
    int dp[1001] = {0,1,2,3,5,9};

    for(int i = 6;i<=n; i++)
        dp[i] = ((dp[i-5] + dp[i-2])%MOD + dp[i-1])%MOD;

    for(int i = 1; i<=n; i++)
    {
        printf("%d ",dp[i]);
    }
    return 0;
}