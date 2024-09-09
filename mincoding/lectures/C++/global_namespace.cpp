#include <stdio.h>
namespace Audio
{
    void init()
    {
        printf("init Audio Module\r\n");
    }
}

namespace Video
{
    void init()
    {
        printf("init Video Module\r\n");
    }
}

void init() { printf("init global Module\r\n"); } // (1) 추가됨

int main()
{
    Video::init();
    Audio::init();
    init();   // (2)
    ::init(); // (3)
}