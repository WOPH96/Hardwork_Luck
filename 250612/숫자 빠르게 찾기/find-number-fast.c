#include <stdio.h>
#define MAX_N 100001
#define MAX_M 100001

int n, m;
int arr[MAX_N];
int queries[MAX_M];

int find(int num)
{
    int left = 1, right = n;
    while(left<=right)
    {
        int mid = (left+right)/2;

        if(arr[mid] == num) return mid;
        else if(arr[mid]<num) left = mid+1;
        else right = mid -1;
    }

    return -1;


}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &queries[i]);
        printf("%d\n",find(queries[i]));
    }
    
    // Please write your code here.
    

    return 0;
}