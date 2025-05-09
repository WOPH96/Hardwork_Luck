#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
int arr[1000];
int n;
void print(const int *mem)
{
    for(int i = 0; i<n;i++)
    {
        printf("%d ",mem[i]);
    }
    printf("\n");
}
int main(void) {

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Please write your code here.

    int mem[1000]= {0};
    
    int max_iter = arr[0]+1;
    for(int i = 0; i<max_iter; i++)
    {
        max_iter = min( ( max( max_iter, arr[i]+1 ) ) , n);
        for(int j = i+1; j<=i+arr[i];j++)
        {
            mem[j] = max(mem[j],mem[i]+1);
        }
    }
    
    int max_jump = -1;
    for(int i = 0; i < n; i++) {
        max_jump = max(max_jump, mem[i]);
    }
    printf("%d",max_jump);
    return 0;
}