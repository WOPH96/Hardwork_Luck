#include <stdio.h>

int arr[101];
int n;
int sum = 0;
int min_val = 0x7fff0000;

#define abs(a) ((a<0)?-a:a) 
#define min(a,b) ((a<b)?a:b)

#define MAX_M 100*1000
int dp[MAX_M];

void init_dp()
{
    for(int i =0 ;i<=n; i++)
    {
        dp[i] = 0x7fff0000;
    }
}

// void backtrack(int idx, int sub_sum)
// {
//     int gap = abs((sum-sub_sum*2));
//     if(gap<min_val)
//     {
//         min_val = gap;
//         // printf("min_val %d\n",min_val);
//     }
//     if(idx>=n) return;

    
//     //선택x
//     backtrack(idx+1,sub_sum);

//     //선택o
//     backtrack(idx+1,sub_sum + arr[idx]);

// }

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];    
    }
    
    // Please write your code here.
    // init_dp();
    // backtrack(0,0);

    dp[0] = 1;
    for(int i = 0 ; i< n; i++)
    {
        for(int s = sum; s>=arr[i]; s--)
        {
            if(dp[s-arr[i]]) dp[s] = 1; // 뒤에서부터 sum을 누적하면, 하나의 요소만 할수있음
        }
    }
    min_val = sum;
    for(int i=1; i<sum; i++)
    {
        if(dp[i])
        {
            int gap = abs((sum - 2*i));
            min_val = min(min_val,gap);       
        }
    }
    printf("%d",min_val);
    return 0;
}