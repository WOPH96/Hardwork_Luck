#include <stdio.h>

#define MAX_N 1005

int n;
int a[MAX_N], b[MAX_N];
int dp[MAX_N];

#define max(a,b) ((a>b)?a:b)

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    // Please write your code here.
    dp[n] = a[n];
    for(int i=n-1;i>=1; i--)
    {
        dp[i] = max(dp[i+1],a[i]);
    }

    int sum = 0;
    for(int i =1; i<=n; i++)
    {
        // printf("%d ",dp[i]);
        if(b[i]<dp[i]) sum+=b[i];
    }
    printf("%d",sum);

    return 0;
}