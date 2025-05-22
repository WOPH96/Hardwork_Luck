#include <stdio.h>
#include <string.h>

#define max(a,b)((a>b)?a:b)

int n, m;
int exp_arr[101], runtime[101];


typedef struct
{
    int e,t;
}Quest;

Quest quest[101];

#define T_MAX 100*100

int dp[T_MAX+1];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &quest[i].e, &quest[i].t);
    }
    
    // Please write your code here.
    memset(dp,-1,(m+1)*sizeof(int));
    dp[0] = 0;


    for(int i = 0; i<n; i++ )
    {
        for(int j = T_MAX; j>=quest[i].t; j--)
        {
            if(dp[j-quest[i].t] >= 0)
            {
                dp[j] = max(dp[j],dp[j-quest[i].t]+quest[i].e);
            }
        }
    
    }
    
    int find = 0;
    for(int i = 0 ;i<=T_MAX; i++)
    {
        if(dp[i]>=m)
        {
            printf("%d",i);
            find = 1;
            break;
        }

    }
    if(!find)
        printf("%d",-1);
    
    return 0;
}