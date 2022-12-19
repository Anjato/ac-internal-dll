#include "pch.h"
#include "debug.h"
#include <vector>

void debug(bool close) 

{

    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);


    if (close)
    {
        if (f != NULL)
        {
            std::cout << "closing debug window";
            fclose(f);
            FreeConsole();
        }
    }

}
