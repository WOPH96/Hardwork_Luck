#include <stdio.h>

int main()
{
    char alpha[4][4] = {
        {'A', 'B', 'K', 'T'},
        {'K', 'F', 'C', 'F'},
        {'B', 'B', 'Q', 'Q'},
        {'T', 'P', 'Z', 'F'}};
    int x, y;

    char c1, c2;
    int cnt = 0;
    scanf("%c %c", &c1, &c2);

    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            if (alpha[y][x] == c1 || alpha[y][x] == c2)
                cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}
