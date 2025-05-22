#include <stdio.h>

int arr[101];
int n;
int sum = 0;
int min_val = 0x7fff0000;

#define abs(a) ((a<0)?-a:a) 
#define min(a,b) ((a<b)?a:b)

int dp[101];

void init_dp()
{
    for(int i =0 ;i<=n; i++)
    {
        dp[i] = 0x7fff0000;
    }
}

void backtrack(int idx, int sub_sum)
{
    int gap = abs((sum-sub_sum*2));
    if(gap<min_val)
    {
        min_val = gap;
        // printf("min_val %d\n",min_val);
    }
    if(idx>=n) return;

    if(dp[idx] < gap) return;
    dp[idx] = gap;

    //선택x
    backtrack(idx+1,sub_sum);

    //선택o
    backtrack(idx+1,sub_sum + arr[idx]);

}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];    
    }
    
    // Please write your code here.
    init_dp();
    backtrack(0,0);

    printf("%d",min_val);
    return 0;
}