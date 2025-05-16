#include <stdio.h>
#define MAX_N 101
#define MAX_W 10001

typedef struct {
    int w;
    int v;
} Jew;

int N, M;
Jew jews[MAX_N];
int max_value = 0;
int max_val_at_weight[MAX_W] = {0}; // 무게 w에서 얻을 수 있는 최대 value

void backtrack(int idx, int sum_weight, int sum_value)
{
    if (sum_weight > M) return;
    if (idx >= N) {
        if (sum_value > max_value) max_value = sum_value;
        return;
    }
    if (max_val_at_weight[sum_weight] && max_val_at_weight[sum_weight] >= sum_value) return;
    max_val_at_weight[sum_weight] = sum_value;

    // 선택
    backtrack(idx+1, sum_weight + jews[idx].w, sum_value + jews[idx].v);
    // 미선택
    backtrack(idx+1, sum_weight, sum_value);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i) scanf("%d %d", &jews[i].w, &jews[i].v);

    backtrack(0, 0, 0);
    printf("%d\n", max_value);

    return 0;
}
