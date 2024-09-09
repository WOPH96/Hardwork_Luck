#include <iostream>
#include <cstdio>
// #include <stdio.h>

using std::cin;
using std::cout;
using std::endl;

#define LED_MAX_CNT (4)
#define LED_ON 1
#define LED_OFF 0

typedef struct
{
    int state = LED_OFF;
    int size;
    int color;
} led_t;

led_t led_arr[LED_MAX_CNT];

void toggle()
{
    char key;
    while (1)
    {

        key = getchar();

        if (key == 0x31)
        {
            led_arr[0].state ^= 1;
        }
        else if (key == 0x32)
        {
            led_arr[1].state ^= 1;
        }

        cout << "led1: " << led_arr[0].state << " led2: " << led_arr[1].state << endl;
    }
}

int main()
{

    cout << "PRESS 1" << endl;
    toggle();

    return 0;
}