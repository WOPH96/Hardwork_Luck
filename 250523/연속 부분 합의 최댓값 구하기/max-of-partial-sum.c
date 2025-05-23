#include <stdio.h>
#define MAX_N 100000
#define max(a,b)((a>b)?a:b)

int n;
int a[MAX_N + 1];
int dp[MAX_N +1];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[i] = -1*0x7fff0000;
    }
    
    // Please write your code here.
    
    dp[0] = a[0];
    int max_val = dp[0];
    for(int i=1; i<n;i++)
    {
        dp[i] = max(dp[i-1]+a[i],a[i]);
        max_val = max(dp[i],max_val);
    }

    printf("%d",max_val);





    return 0;
}