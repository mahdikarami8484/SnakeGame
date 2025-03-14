#include "core/Console.h"

Console::Console()
{
    this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Console::get_info()
{   
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        
        this->info = {static_cast<SHORT>(width), static_cast<SHORT>(height), csbi}; 
    } else {
        std::cerr << "Error retrieving console size!" << std::endl;
    }
}

void Console::moveCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(hConsole, coord);
}

void Console::clear()
{
    DWORD dwWritten;
    FillConsoleOutputCharacter(hConsole,
        ' ',
        this->info.size.X * this->info.size.Y,
        {0, 0},
        &dwWritten
    );

    FillConsoleOutputAttribute(hConsole, 
        this->info.csbi.wAttributes, 
        this->info.size.X * this->info.size.Y,
        {0, 0}, 
        &dwWritten
    );

    moveCursor(0, 0);
}

void Console::write(std::string chars,
    Colors color = WHITE,
    Colors bg = BLACK,
    Text_Attr text_attr = NORMAL,
    bool endline = false,
    COORD pos = {-1, -1}
){
    if(pos.X >= 0 && pos.Y > 0)
        moveCursor(pos.X, pos.Y);

    // Set Attribute 
    SetConsoleTextAttribute(
        hConsole, 
        static_cast<WORD>(color) |
        static_cast<WORD>(bg) << 4 |
        static_cast<WORD>(text_attr)
    );

    // Print chars
    std::cout << chars << ((endline) ? "\n" : "");

    // Reset 
    SetConsoleTextAttribute(
        hConsole,
        DEFAULT_COLOR |
        DEFAULT_BACKGROUND_COLOR << 4
    );
}

