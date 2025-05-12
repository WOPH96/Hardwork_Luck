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

    return src->end > dst->end;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &segments[i].start, &segments[i].end);
    }
    // Please write your code here.

    qsort(segments,n,sizeof(Line),cmp);

    for(int i =0; i<n; i++)
    {
        // printf("%d %d\n",segments[i].start,segments[i].end);
    }

    return 0;
}