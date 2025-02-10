#define RAYGUI_IMPLEMENTATION
#include "Core.h"

int main(void)
{
    Core *core = new Core();
    core->Run();
    delete core;
    return 0;
}

// inheretance