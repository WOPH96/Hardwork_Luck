#include <stdio.h>

int main()
{
    int acc_nums[6];
    int i = 0;
    for (; i < 6; i++)
    {
        scanf("%d", &acc_nums[i]);
        if (i > 0)
        {
            acc_nums[i] += acc_nums[i - 1];
        }
    }

    for (i = 0; i < 6; i++)
    {
        printf("%d ", acc_nums[i]);
    }
    return 0;
}
