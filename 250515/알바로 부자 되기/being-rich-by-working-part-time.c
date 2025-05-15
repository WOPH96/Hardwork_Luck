#include <stdio.h>
#define MAX_NUM 1000
#define max(a,b) ((a>b)?a:b)
typedef struct
{
    int s,e,p;
}Job;

Job jobs[MAX_NUM+1];


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &jobs[i].s, &jobs[i].e, &jobs[i].p);
    }
    
    // Please write your code here.
    
    int dp[MAX_NUM+1] ={0};
    for(int i = 0; i <n; i++)
    {
        dp[i] = jobs[i].p;
        for(int j=0; j<i; j++)
        {
            if (jobs[j].e < jobs[i].s)
                dp[i] = max(dp[i-1],dp[j]+jobs[i].p);
        }
        // if(i > 0) dp[i] = max(dp[i], dp[i-1]); // i-1까지의 최대값 그대로 유지 가능
    }

    int max_val = -1;
    for(int i =0 ; i<n; i++)
    {
        max_val = max(max_val,dp[i]);
    }

    printf("%d",max_val);
    return 0;
}