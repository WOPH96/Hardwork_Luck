#include <stdio.h>
#define MAX_LEN 1000
#define NUMBER_OF_LINE 5
int main()
{
    FILE *fs;
    char str[NUMBER_OF_LINE][MAX_LEN];
    int num = 0;

    fs = fopen("3-1_input.txt", "r");
    if (fs == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while (fgets(str[num], MAX_LEN, fs) != NULL) {
        printf("%s", str[num]);
        num++;
    }

    fclose(fs);
    return 0;
}
