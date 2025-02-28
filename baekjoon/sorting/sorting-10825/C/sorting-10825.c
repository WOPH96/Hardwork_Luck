#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001
#define NAME_SIZE 11
// 필요 변수 선언

int n;

typedef struct
{
    char name[NAME_SIZE];
    int kor, eng, mat;

} Student;

Student students[MAX_SIZE];

// 필요 변수 선언

#define DESCENDING(a, b) ((a) < (b) ? 1 : (a) > (b) ? -1 \
                                                    : 0)
#define ASCENDING(a, b) ((a) > (b) ? 1 : (a) < (b) ? -1 \
                                                   : 0)

void print_debug();

int mystrcmp(const char *a, const char *b)
{
    while (*a && (*a == *b))
    {
        a++;
        b++;
    }
    return *a - *b;
}

int compare(const void *a, const void *b)
{
    Student *first = (Student *)a;
    Student *second = (Student *)b;
    int result;
    if ((result = DESCENDING(first->kor, second->kor)) != 0)
        return result;
    if ((result = ASCENDING(first->eng, second->eng)) != 0)
        return result;
    if ((result = DESCENDING(first->mat, second->mat)) != 0)
        return result;
    return mystrcmp(first->name, second->name);
    // if (first->kor == second->kor)
    // {
    //     if (first->eng == second->eng)
    //     {
    //         if (first->mat == second->mat)
    //         {
    //             return (first->name > second->eng) - (first->name < second->name);
    //         }
    //         else
    //             return (first->mat < second->mat) - (first->mat > second->mat);
    //     }
    //     else
    //         return (first->eng > second->eng) - (first->eng < second->eng);
    // }
    // else

    //     return (first->kor < second->kor) - (first->kor > second->kor);
}
void sol()
{
    qsort(students, n, sizeof(Student), compare);
}

void input_f()
{
    FILE *fp = fopen("sorting-10825_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d ", &n);
    for (register int i = 0; i < n; i++)
    {
        fscanf(fp, "%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].mat);
        // printf("%s %d %d %d\n", students[i].name, students[i].kor, students[i].eng, students[i].mat);
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%d ", &n);
    for (register int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].mat);
        // printf("%s %d %d %d\n", students[i].name, students[i].kor, students[i].eng, students[i].mat);
    }
    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    // print_debug();
    sol();
    // printf("\n");
    print_debug();

    return 0;
}

void print_debug()
{
    for (register int i = 0; i < n; i++)
    {
        // fscanf(fp, "%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].mat);
        // printf("%s %d %d %d\n", students[i].name, students[i].kor, students[i].eng, students[i].mat);
        printf("%s\n", students[i].name);
    }
}
