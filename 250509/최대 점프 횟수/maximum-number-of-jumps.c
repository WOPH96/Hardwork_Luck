#include <stdio.h>
#define max(a,b) ((a>b)?a:b)

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

    // mem[i]: i번 칸까지 점프해서 도달한 최대 점프 횟수, 도달못하면 -1
    int mem[1000];
    for(int i=0;i<n;i++) mem[i]=-1;
    mem[0]=0;

    for(int i=0; i<n; i++) 
    {
        if(mem[i]==-1) continue; // 밟을 수 없는 칸은 스킵
        for(int j=1; j<=arr[i]; j++) 
        {
            if(i+j < n) {
                mem[i+j] = max(mem[i+j], mem[i]+1);
            }
        }
    }
    // print(mem);

    int max_jump = -1;
    for(int i = 0; i < n; i++) {
        max_jump = max(max_jump, mem[i]);
    }
    printf("%d",max_jump);
    return 0;
}
