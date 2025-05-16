#include <stdio.h>

int n, m;
int arr[100];
#define MAX_VAL 0x7fff0000

int min_length = MAX_VAL;
#define min(a,b) ((a<b)?a:b)

// void backtrack(int sum, int idx, int cnt)
// {
//     if(sum == m)
//     {
//         min_length = min(cnt,min_length);
//         return;
//     }

//     if(idx>=n) return;
//     if(sum > m || cnt >= min_length) return;

//     //현재 요소 선택했을때
//     backtrack(sum+arr[idx],idx+1,cnt+1);

//     //현재 요소 선택x
//     backtrack(sum,idx+1,cnt);
// }

// int main() {
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
    
//     // Please write your code here.
    
//     // 합이 12가 될때 리턴하도록 

//     backtrack(0,0,0);

//     if(min_length == MAX_VAL)
//         printf("-1");
//     else
//         printf("%d",min_length);

//     return 0;
// }

int main() 
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //dp[i] -> 지금까지 선택한 수들의 합이 i일때, 가능한 최소 수열의 길이


    int dp[10001] = {0};

    for(int i =1;                  i<=m;i++)
    {
        dp[i]= MAX_VAL;
    }

    //dp[5, 1, 20, 3, 4] -> 1
    //dp[6 21 ]

    for(int i=0; i<n; i++)
    {
        for(int j=m;j>=0;j--)
        {
            if(j>= arr[i])
                dp[j] = min(dp[j],dp[j - arr[i]] +1);
        }
    }

    if(dp[m] == MAX_VAL)
        printf("-1");
    else
        printf("%d",dp[m]);
}