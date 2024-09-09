#include <stdio.h>

void func3(int (*arr)[3], int b) // 소괄호를 쳐줘야, 얘가 포인터 변수라는 것을 안다.
{
    int size = sizeof(*arr) / sizeof(b);
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", *(*(arr + i) + j));
            // printf("%d ", (*(arr + i))[j]);
            // printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void func4(int (*parr)[2][3], int b, int c)
{
    // printf("%d", parr[0][0][0]);
    printf("%d", *(*(*(parr) + 1) + 1));
}
int main()
{

    int a = 3;
    float f = 3.14f;

    a = f;

    printf("%d\n", a);

    char c1 = 1;
    unsigned char c2 = 1;

    c1 <<= 1;
    c2 <<= 1;

    printf("%d %d \n", c1, c2);

    int arr3[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    func3(arr3, 2); // 의 parameter는 무엇일까?

    int arr4[4][2][3];

    // for(int i=0; i<4*2*3;i++){

    // }

    func4(arr4, 2, 3);
    return 0;
}