#include <stdio.h>
#define max(a,b) ((a>b) ? a : b)
int n;
int num[1001];

void print(int * mem)
{
    for(int i =0; i<n; i++)
    {
        printf("%d ",mem[i]);
    }
    printf("\n");
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    // Please write your code here.

    int mem[1001] = {-1};
    mem[0] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num[j]>num[i])
            {
                mem[j] = max(mem[j],mem[i]+1);
            }
            // printf("[%d %d]\n",i,j);
            // print(mem);
        }
    }
    int longest = -1;
    for(int i = 0; i<n; i++)
    {
        longest = max(longest, mem[i]);
    }
    printf("%d",longest);
    return 0;
}