#include <stdio.h>
#include <string.h>
// 필요 변수 선언
typedef struct
{
    int age;
    char name[8];
} info;

info train[7] = {
    {15, "summer"},
    {33, "cloe"},
    {24, "summer"},
    {28, "niki"},
    {32, "jenny"},
    {20, "summer"},
    {40, "coco"}};

info woman;
// 필요 변수 선언
int is_same(int idx);
void input_f()
{
    FILE *fp = fopen("19-6_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%s %d", woman.name, &woman.age);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%s %d", woman.name, &woman.age);

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();

    // printf("%s %d", woman.name, woman.age);
    int size = sizeof(train) / sizeof(info);
    for (int i = 0; i < size; i++)
    {

        if (is_same(i))
        {
            printf("%d", i);
            return 0;
        }
    }
    return -1;
}

int is_same(int idx)
{
    // printf("%d\n", strcmp(train[idx].name, woman.name));
    if (!(strcmp(train[idx].name, woman.name)) && train[idx].age == woman.age)
        return 1;
    return 0;
}