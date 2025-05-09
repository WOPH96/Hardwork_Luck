#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
int n;
int arr[1000];

void print(const int *mem)
{
    for(int i = 0 ; i<n ;i++)
    {
        printf("%d ",mem[i]);
    }
    printf("\n");
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Please write your code here.
    
    int mem[1001] = {0};
    mem[0] = 1;
    for(int i = 1; i<n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(mem[i] == 0)
                mem[i] = 1;
            if(arr[i] < arr[j]) // 다음게 이전것보다 작으면 감소하는 수열
                mem[i] = max(mem[i],mem[j]+1); 
            // printf("[%d,%d]\n",i,j);
            // print(mem);
        }
    }

    int longest = -1;
    for(int i = 0; i<n; i++)
    {
        longest = max(longest,mem[i]);
    }

    printf("%d",longest);

    return 0;
}