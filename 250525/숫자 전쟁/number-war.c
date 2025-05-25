#include <stdio.h>

#define MAX_N 1005

int n;
int enemy[MAX_N], me[MAX_N];
int dp[MAX_N][MAX_N];

#define max(a,b) ((a>b)?a:b)

int dfs(int i, int j)
{
    if(i==n || j==n) return 0;

    if(dp[i][j] != -1 ) return dp[i][j];

    int ret = 0;

    if(me[j] < enemy[i]) // 내 카드가 작은 경우
    {
        ret = max(ret,dfs(i,j+1)+me[j]);
    }
    else
    {
        ret = max(ret,dfs(i+1,j)); // 상대방 카드가 큰 경우
    }
    ret = max(ret,dfs(i+1,j+1)); // 버리는 경우 

    

    dp[i][j] = ret;
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &enemy[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &me[i]);
    }
    // Please write your code here.
    
    for(int i= 0;i<=n; i++)
    {
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;
    }

    dfs(0,0);
    
    printf("%d",dp[0][0]);


    return 0;
}