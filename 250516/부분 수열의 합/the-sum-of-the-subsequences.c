#include <stdio.h>

int n, m;
int arr[101];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Please write your code here.
    
    int dp[10001] = {0};
    for(int i = 1; i<=m;i++)
    {
        dp[i] = -1;
    }
    //dp[i] = i를 만들 수 있으면 1 업승면 0

    for(int i = 0; i<n; i++)
    {
        for(int j =m; j>=1; j--)
        { 
            if(j >= arr[i] && dp[j - arr[i]] != -1 )
            {
                dp[j] = 1;
            }
        }
    }

    if(dp[m] == 1) printf("Yes");
    else printf("No");

    return 0;
}