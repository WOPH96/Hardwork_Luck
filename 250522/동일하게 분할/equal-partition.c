#include <stdio.h>
#include <string.h>
#define MAX_S 100*1000
int n;
int arr[101];
int sum = 0;
int dp[MAX_S];

int abs(int a)
{
    return a<0 ? -a:a;
}

int main() {
    // Please write your code here.

    scanf("%d",&n);
    for(int i =0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    if(sum%2==1)
    {
        printf("No");
        return 0;
    }

    int target = sum/2;
    
    // memset(dp,-1,sizoef(int)*(sum+1));
    dp[0] = 1;
    for(int i =0; i<n; i++)
    {
        for(int j =sum; j>=arr[i];j--)
        {
            if(dp[j-arr[i]])
            {
                dp[j] = 1;
                if(j == target)
                {
                    printf("Yes");
                    return 0;
                }
            }
        }
    }
    

    return 0;
}