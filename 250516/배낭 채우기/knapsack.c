#include <stdio.h>
#include <stdlib.h>
int N, M;

typedef struct
{
    int w;
    int v;
}Jew;

int cmp(const void* a, const void* b)
{
    Jew* src = (Jew*)a;
    Jew* dst = (Jew*)b;
    return src->w > dst->w;
}

Jew jews[101];

void print()
{
    for(int i= 0; i<N; i++)
    {
        printf("[%d %d]\n", jews[i].w, jews[i].v);
    }
    printf("\n");
}

int max_value = -1;

// int max_arr[10001][101];
int max_arr[101];

void backtrack(int idx, int sum_weight, int sum_value)
{

    if(sum_weight > M ) return;
    if(max_value < sum_value) 
        max_value = sum_value;
    if(idx >= N) return;

    // if(max_arr[sum_weight][idx] && max_arr[sum_weight][idx] < sum_value) return;
    //     max_arr[sum_weight][idx] = sum_value;

    if(max_arr[idx] && max_arr[idx] < sum_value) return;
    max_arr[idx] = sum_value;

    //선택 할 떄
    backtrack(idx+1, sum_weight+jews[idx].w, sum_value+jews[idx].v);

    //선택 x
    backtrack(idx+1, sum_weight, sum_value);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jews[i].w, &jews[i].v);
    }
    
    // Please write your code here.

    // print();

    qsort(jews,N,sizeof(Jew),cmp);
    backtrack(0,0,0);

    printf("%d",max_value);


    // print();
    return 0;
}