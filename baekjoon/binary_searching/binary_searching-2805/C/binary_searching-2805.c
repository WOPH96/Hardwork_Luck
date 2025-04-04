#include <stdio.h>

#define MAX_TREE 1000001
// 필요 변수 선언
long long n, target;
// 필요 변수 선언
long long trees[MAX_TREE];
void print_debug();

long long max_height = -1;

long long getWood(long long height)
{
    long long result = 0;
    for (long long i = 0; i < n; i++)
    {
        if (trees[i] > height)
        {
            result += trees[i] - height;
        }
    }
    return result;
}

void sol()
{
    // printf("%lld", max_height);
    long long left = 0;
    long long right = max_height;
    long long answer = 0;
    while (left <= right)
    {
        // 최적높이 설정
        long long mid = (left + right) / 2;
        // 높이에서 얻을수있는 목재 수
        long long wood = getWood(mid);

        // 목재 수가 목적보다 많다면-> 목재 개수를 줄여보자, 다만 만족은 했으니 저장
        // -> height를 늘여야함 -> left를 mid보다 크게
        if (wood >= target)
        {
            answer = mid;
            left = mid + 1;
        }
        // 목재 수가 목적보다 작다면-> 더 많이 얻어야함 -> height를 줄여야함 -> right를 mid보다 작게
        else
        {
            right = mid - 1;
        }
        // else
        // {
        //     printf("%lld", mid);
        //     return;
        // }
    }
    printf("%lld", answer);
}

void input_f()
{
    FILE *fp = fopen("binary_searching-2805_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%lld %lld", &n, &target);

    for (long long i = 0; i < n; i++)
    {
        fscanf(fp, "%lld", &trees[i]);
        max_height = max_height > trees[i] ? max_height : trees[i];
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%lld ",  &num2);
    scanf("%lld %lld", &n, &target);

    for (long long i = 0; i < n; i++)
    {
        scanf("%lld", &trees[i]);
        max_height = max_height > trees[i] ? max_height : trees[i];
    }
    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    print_debug();
    sol();

    return 0;
}

void print_debug()
{
}
