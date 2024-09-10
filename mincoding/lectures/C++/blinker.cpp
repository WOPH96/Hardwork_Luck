#include <stdio.h>
#include <windows.h>

void set_color(unsigned short text, unsigned short back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
void test()
{
    unsigned short back = 0;
    for (int i = 0; i < 16; i++)
    {
        set_color(i, back);
        printf("Hello %d, %d\n", i, back);
    }
}

#define RED 4
#define YELLOW 6
#define GREEN 10
#define GRAY 8
#define WHITE 15

void show_traffic_light()
{
    printf("\r\n");
    printf("┏━━━━━━━━━┓\r\n");
    printf("┃ ");
    set_color(RED, 0);
    printf("● ");
    set_color(YELLOW, 0);
    printf("● ");
    set_color(GREEN, 0);
    printf("●");
    set_color(WHITE, 0);
    printf("┃");
    printf("\r\n");
    printf("┗━━━━━━━━━┛\r\n");
    printf("\r\n");
    set_color(WHITE, 0);
}

int main(void)
{
    // test();
    show_traffic_light();
    return 0;
}
