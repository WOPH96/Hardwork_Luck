#include "gpio_driver.h"
#include "stdint.h"
#include <stdio.h>

// #ifdef __INF__
// void INF_gpio_init();
// void INF_gpio_write(uint8_t abc);
// uint8_t INF_gpio_read();
// #elif defined __AVR__
// void AVR_gpio_init();
// void AVR_gpio_write(uint8_t abc);
// uint8_t AVR_gpio_read();
// #elif defined __VS__
// void vs_gpio_init();
// void vs_gpio_write(uint8_t abc);
// uint8_t vs_gpio_read();
// #endif

void gpio_init()
{
#ifdef __INF__

#elif defined __AVR__

#elif defined __VS__
    vs_gpio_init();
#endif
}
uint8_t gpio_read()
{
#ifdef __INF__

#elif defined __AVR__

#elif defined __VS__
    return vs_gpio_read();
#endif
    return 1;
}
void gpio_write(uint8_t abc)
{
#ifdef __INF__

#elif defined __AVR__
#elif defined __VS__
    vs_gpio_write(abc);
#endif
}

#ifdef __INF__
void INF_gpio_init()
{
}
void INF_gpio_write(uint8_t abc)
{
}
uint8_t INF_gpio_read()
{
}
#elif defined __AVR__

#elif defined __VS__
void vs_gpio_init()
{
    printf("hello\n");
}
void vs_gpio_write(uint8_t abc)
{
    printf("hello\n");
}
uint8_t vs_gpio_read()
{
    printf("hello\n");
    return 1;
}
#endif