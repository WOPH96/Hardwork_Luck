#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int n;

typedef struct
{
    int start, end;
}Line;

Line segments[MAX_N];

int cmp(const void *a, const void *b)
{
    Line *src = (Line*)a;
    Line *dst = (Line*)b;

    if(src->end == dst->end)
    {
        return src->start > dst->start;
    }
    return src->end > dst->end;
    
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &segments[i].start, &segments[i].end);
    }
    // Please write your code here.

    qsort(segments,n,sizeof(Line),cmp);

    int mem[1000] = {0};
    int idx = 1;
    for(int i =0; i<n; i++)
    {
        // printf("%d %d\n",segments[i].start,segments[i].end);
        if(mem[idx-1] < segments[i].start)
        {
            // printf("mem[%d] : %d segment->[%d,%d]\n",
            //         idx,mem[idx],segments[i].start,segments[i].end);
            mem[idx++] = segments[i].end;
            
        }

    }
    printf("%d",idx-1);
    // for(int i =0; i<idx; i++)
    // {
    //     printf("%d\n",mem[i]);
    //     // if(mem[idx] < segments[i].start)
    //     // {
    //     //     mem[idx++] = segments[i].end;
    //     // }

    // }
    return 0;
}