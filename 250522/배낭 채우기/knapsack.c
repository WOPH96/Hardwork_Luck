#include <stdio.h>
#include <string.h>
int n, m;
int weight[101], value[101];

typedef struct
{
    int w,v;
}Jew;

Jew jews[101];

#define max(a,b) ((a>b)?a:b)

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jews[i].w, &jews[i].v);
    }
    
    // Please write your code here.
    int dp[10001];
    memset(dp,-1,(m+1)*sizeof(int));
    dp[0] = 0;
    // printf("%d",dp[m]);
    for(int i =0; i<=n; i++)
    {
        for(int cur_w=m; cur_w>=jews[i].w;cur_w--)
        {
            if(dp[cur_w-jews[i].w]>=0)
            {
                dp[cur_w] = max(dp[cur_w],dp[cur_w-jews[i].w]+jews[i].v);
            }
        }
    }
    // for(int i =0; i<=m; i++)
    // {
    //     printf("%d ",i);
    // }
    // printf("\n");
    int max_value = -1;
    for(int i =0; i<=m; i++)
    {
        // if(dp[i]==-1) printf("X ");
        // else    printf("%d ",dp[i]);
        max_value = max(max_value,dp[i]);
    }
    printf("%d",max_value);

    return 0;
}