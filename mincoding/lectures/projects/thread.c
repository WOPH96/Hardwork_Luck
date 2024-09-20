#include <stdio.h>
#include <stdint.h>
#include <time.h>
#ifdef _WIN64
#include <conio.h>
#endif
#define TASK_COUNT (3)
#define ONE_TASK_PERIOD (1000)   // ms
#define TWO_TASK_PERIOD (2000)   // ms
#define THREE_TASK_PERIOD (3000) // ms

void Task(const char *func_name)
{
    printf("%s() ", func_name);
}
void delay_ms(const long long dtime)
{
    clock_t start = clock();
    uint32_t i = 0;
    long long dtime_s = dtime / 1000;
    uint8_t key = 0;
    for (i = 0; i < 10000000; i++)
    {
        double sec = (double)(clock() - start) / CLOCKS_PER_SEC;
#ifdef _WIN64
        if (_kbhit())
        {
            key = _getch();
            printf("\nPressed %c", key);
        }
#endif

        if (sec >= dtime_s)
            break;
    }
}
int main()
{
    void (*fp_arr[TASK_COUNT])(const char *) =
        {Task, Task, Task};
    const char *names[TASK_COUNT] =
        {"func1", "func2", "func3"};

    // fp_arr[0](names[0]);

    int need_delay[TASK_COUNT] = {ONE_TASK_PERIOD, TWO_TASK_PERIOD, THREE_TASK_PERIOD};

    int task_timer[TASK_COUNT] = {0};
    int timer = 0;
    while (1)
    {
        printf("[%d] :", timer);
        for (int i = 0; i < TASK_COUNT; i++)
        {
            if (task_timer[i] >= need_delay[i])
            {

                fp_arr[i](names[i]);
                task_timer[i] = 0;
            }
        }
        printf("\n");
        delay_ms(1000);
        for (int i = 0; i < TASK_COUNT; i++)
        {
            task_timer[i] += 1000;
        }
        timer++;
    }

    return 0;
}