#include <stdio.h>
#include <ncurses.h>

void set_color(int text, int back)
{
    attron(COLOR_PAIR(text + 1 + (back * 16)));
}

void test()
{
    int back = 0;
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
#define BLACK 0

void show_traffic_light()
{
    printw("\r\n");
    printw("┏━━━━━━━━━┓\r\n");
    printw("┃ ");
    set_color(RED, 0);
    printw("● ");
    set_color(YELLOW, 0);
    printw("● ");
    set_color(GREEN, 0);
    printw("●");
    set_color(WHITE, 0);
    printw("┃");
    printw("\r\n");
    printw("┗━━━━━━━━━┛\r\n");
    printw("\r\n");
    set_color(WHITE, 0);
}

int main(void)
{
    initscr();     // Initialize ncurses
    start_color(); // Initialize color pairs

    // Create color pairs
    init_pair(1, RED, BLACK);
    init_pair(2, YELLOW, BLACK);
    init_pair(3, GREEN, BLACK);
    init_pair(4, GRAY, BLACK);
    init_pair(5, WHITE, BLACK);

    // test();
    show_traffic_light();

    getch();  // Wait for a key press
    endwin(); // End ncurses mode

    return 0;
}