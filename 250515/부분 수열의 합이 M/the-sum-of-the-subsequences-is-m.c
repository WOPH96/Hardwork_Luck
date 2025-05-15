#include <stdio.h>

int n, m;
int arr[100];
#define MAX_VAL 0x7fff0000

int min_length = MAX_VAL;
#define min(a,b) ((a<b)?a:b)

void backtrack(int sum, int idx, int cnt)
{
    if(sum == m)
    {
        min_length = min(cnt,min_length);
        return;
    }

    if(idx>=n) return;

    //현재 요소 선택했을때
    backtrack(sum+arr[idx],idx+1,cnt+1);

    //현재 요소 선택x
    backtrack(sum,idx+1,cnt);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Please write your code here.
    
    // 합이 12가 될때 리턴하도록 

    backtrack(0,0,0);

    if(min_length == MAX_VAL)
        printf("-1");
    else
        printf("%d",min_length);

    return 0;
}