#include <windows.h>
#include <iostream>
#include <random>
#include <ctime>

int main()
{
    int view = 0;

    Console console = Console();

    // Views 
    Menu_view menu = Menu_view(&console, &view);
    console.get_info();

    Game_view game = Game_view(&console);

    console.clear();

    Sleep(500);

    while(true)
    {
        console.get_info();
        
        if (GetAsyncKeyState('Q') & 0x8000) 
        {
            console.clear();
            break;
        }

        // Handle Views
        switch (view)
        {
            case 0:
                /* Menu */
                menu.update();
                break;
            case 1:
                /* Game */
                game.start();
                game.update();
                break;
        }

        /* i dont know why have error ): */
        // std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay));

        Sleep(frameDelay);
    }

    return 0;
}