#include <stdio.h>

#define MAX_SIZE 100100
#define INF 0x7fff0000
#define N_INF 0xffff0000
// 필요 변수 선언
int heap[MAX_SIZE]; // 1부터 시작
int hn = 0;
// 필요 변수 선언
int n;
void print_debug();

void sol()
{
}

void push(int *heap, int *hn, int data)
{
    heap[++(*hn)] = data;
    register int tmp;
    for (register int i = *hn; i > 1; i /= 2) // heap 현재 노드는 자기 자식보다만 작으면 됨
    {
        // 현재 노드(자식)가,부모 노드보다 작으면 부모 자식 스왑

        if (heap[i] >= heap[i / 2]) // 자식 < 부모 성립해야함
            // 자식이 부모보다 크거나 같다면
            break; // 올바르게 들어간 것이므로 스왑 x
        else
        { // 자식이 부모보다 작다면
            tmp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = tmp;
        }
    }
}

int pop(int *heap, int *hn)
{
    if (*hn == 0)
        return 0;
    int ret = heap[1];
    heap[1] = heap[(*hn)];
    heap[(*hn)--] = INF; // 큰값, 비교를 위함
    // 2개 있었다면, hn = 1

    register int tmp;
    // 1에서부터 내려가면서, 부모보다 작은 자식이 있는지 찾기
    for (register int i = 1; i * 2 <= (*hn);)
    {
        if (heap[i] < heap[i * 2] && heap[i] < heap[i * 2 + 1])
            break;

        else
        {
            if (heap[i * 2] < heap[i * 2 + 1])
            {
                tmp = heap[i];
                heap[i] = heap[i * 2];
                heap[i * 2] = tmp;
                i = i * 2;
            }
            else
            {
                tmp = heap[i];
                heap[i] = heap[i * 2 + 1];
                heap[i * 2 + 1] = tmp;
                i = i * 2 + 1;
            }
        }
    }
    return ret;
}

void input_f()
{
    FILE *fp = fopen("priority_queue-1927_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d ", &n);
    for (int i = 0; i < n; i++)
    {
        int input;
        fscanf(fp, "%d", &input);
        if (input == 0)
        {
            printf("%d\n", pop(heap, &hn));
        }
        else
        {
            push(heap, &hn, input);
        }
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        if (input == 0)
        {
            printf("%d\n", pop(heap, &hn));
        }
        else
        {
            push(heap, &hn, input);
        }
    }

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    print_debug();
    sol();

    return 0;
}

void print_debug()
{
}
