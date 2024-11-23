#ifndef __GPIO_DRIVER_H__
#define __GPIO_DRIVER_H__
#include "config.h"
#include "common.h"
#include "stdint.h"

#ifdef __INF__
void INF_gpio_init();
void INF_gpio_write(uint8_t abc);
uint8_t INF_gpio_read();
#elif defined __AVR__
void AVR_gpio_init();
void AVR_gpio_write(uint8_t abc);
uint8_t AVR_gpio_read();
#elif defined __VS__
void vs_gpio_init();
void vs_gpio_write(uint8_t abc);
uint8_t vs_gpio_read();
#endif

void gpio_init();
uint8_t gpio_read();
void gpio_write(uint8_t);

#endif
